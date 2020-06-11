#include <iostream>
#include <string>

class Ball
{
private:
  std::string m_color{ "black" };
  double m_radius{ 10.0 };

public:
  Ball() = default;

  Ball(const std::string &color)
  {
    m_color = color;
  }

  Ball(double radius)
  {
    m_radius = radius;
  }

  Ball(const std::string &color, double radius)
  {
    m_color = color;
    m_radius = radius;
  }

  void print()
  {
    std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
  }
};

int main()
{
  Ball def{ };
  def.print();

  Ball blue{ "blue" };
  blue.print();

  Ball twenty{ 20.0 };
  twenty.print();

  Ball blueTwenty{ "blue", 20.0 };
  blueTwenty.print();

  return 0;
}
