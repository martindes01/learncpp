#include <iostream>

class Point
{
private:
  double m_x{ };
  double m_y{ };
  double m_z{ };

public:
  Point (double x=0.0, double y=0.0, double z=0.0) : m_x{ x }, m_y{ y }, m_z{ z } { }

  bool operator!() const;

  Point operator+() const;

  Point operator-() const;
};

bool Point::operator!() const
{
  return ((m_z == 0.0) && (m_z == 0.0) && (m_z == 0.0));
}

Point Point::operator+() const
{
  return *this;
}

Point Point::operator-() const
{
  return Point( -m_x, -m_y, -m_z );
}

int main()
{
  Point point{ };

  if (!point)
    std::cout << "point is set at the origin\n";
  else
    std::cout << "point is not set at the origin\n";

  return 0;
}
