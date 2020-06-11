#include <iostream>

// forward declaration of Vector3d class
class Vector3d;

class Point3d
{
private:
  double m_x{ };
  double m_y{ };
  double m_z{ };

public:
  Point3d(double x=0.0, double y=0.0, double z=0.0) : m_x{ x }, m_y{ y }, m_z{ z } { }

  void print() const
  {
    std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
  }

  // forward declaration of Point3d::moveByVector() member function
  void moveByVector(const Vector3d &v);
};

class Vector3d
{
private:
  double m_x{ };
  double m_y{ };
  double m_z{ };

public:
  Vector3d(double x=0.0, double y=0.0, double z=0.0) : m_x{ x }, m_y{ y }, m_z{ z } { }

  void print() const
  {
    std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
  }

  // set Point3d::moveByVector() member function as friend of Vector3d
  // Point3d::moveByVector() member function is visible to compiler since it is declared above
  friend void Point3d::moveByVector(const Vector3d &v);
};

// define Point3d::moveByVector() member function
void Point3d::moveByVector(const Vector3d &v)
{
  m_x += v.m_x;
  m_y += v.m_y;
  m_z += v.m_z;
}

int main()
{
  Point3d p{ 1.0, 2.0, 3.0 };
  Vector3d v{ 2.0, 2.0, -3.0 };

  p.print();
  p.moveByVector(v);
  p.print();

  return 0;
}
