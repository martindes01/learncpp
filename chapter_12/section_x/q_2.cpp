#include <iostream>
#include <vector>

class Point
{
private:
  int m_x{ };
  int m_y{ };
  int m_z{ };

public:
  Point(int x=0, int y=0, int z=0) : m_x{ x }, m_y{ y }, m_z{ z } { }

  friend std::ostream& operator<<(std::ostream &out, const Point &point)
  {
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

    return out;
  }
};

class Shape
{
public:
  virtual ~Shape() { }

  virtual std::ostream& print(std::ostream &out) const = 0;

  friend std::ostream& operator<<(std::ostream &out, const Shape &shape)
  {
    return shape.print(out);
  }
};

class Circle : public Shape
{
private:
  Point m_o{ };
  int m_radius{ };

public:
  Circle(const Point &o, int radius) : m_o{ o }, m_radius{ radius } { }

  virtual std::ostream& print(std::ostream &out) const override
  {
    out << "Circle(" << m_o << ", radius " << m_radius << ')';

    return out;
  }

  int getRadius() const { return m_radius; };
};

class Triangle : public Shape
{
private:
  Point m_a{ };
  Point m_b{ };
  Point m_c{ };

public:
  Triangle(const Point &a, const Point &b, const Point &c) : m_a{ a }, m_b{ b }, m_c{ c } { }

  virtual std::ostream& print(std::ostream &out) const override
  {
    out << "Triangle(" << m_a << ", " << m_b << ", " << m_c << ')';

    return out;
  }
};

// return the largest Circle radius from a vector of Shape pointers
int getLargestRadius(const std::vector<Shape*> &vector)
{
  // create placeholder for largest radius
  int largestRadius{ };

  for (auto *pShape : vector)
  {
    // downcast Shape* to Circle*
    Circle *pCircle = dynamic_cast<Circle*>(pShape);

    // check whether downcast successful
    if (pCircle)
    {
      // update largest radius
      if (pCircle->getRadius() > largestRadius)
      {
        largestRadius = pCircle->getRadius();
      }
    }
  }

  // return largest radius
  return largestRadius;
}

int main()
{
  std::vector<Shape*> v{ };
  v.push_back(new Circle( Point( 1, 2, 3 ), 7 ));
  v.push_back(new Triangle( Point( 1, 2, 3 ), Point( 4, 5, 6 ), Point( 7, 8, 9 ) ));
  v.push_back(new Circle( Point( 4, 5, 6 ), 3 ));

  // print value of each Shape pointer in v
  for (const auto pShape : v)
  {
    std::cout << *pShape << '\n';
  }

  std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

  // delete each (pointer) element from v
  for (const auto pShape : v)
  {
    delete pShape;
  }

  return 0;
}
