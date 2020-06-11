#include <cmath>
#include <iostream>

class Point2d
{
private:
  double m_x{ };
  double m_y{ };

public:
  Point2d(double x=0.0, double y=0.0) : m_x{ x }, m_y{ y } { }

  void print() const
  {
    std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
  }

  double distanceTo(const Point2d &other) const
  {
    return std::sqrt((other.m_x - m_x) * (other.m_x - m_x) + (other.m_y - m_y) * (other.m_y - m_y));
  }

  friend double distanceFrom(const Point2d &a, const Point2d &b);
};

double distanceFrom(const Point2d &a, const Point2d &b)
{
  return std::sqrt((b.m_x - a.m_x) * (b.m_x - a.m_x) + (b.m_y - a.m_y) * (b.m_y - a.m_y));
}

int main()
{
  Point2d first{ };
  Point2d second{ 3.0, 4.0 };

  first.print();
  second.print();

  std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
  std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

  return 0;
}
