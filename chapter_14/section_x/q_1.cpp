#include <iostream>
#include <stdexcept> // std::runtime_error

class Fraction
{
private:
  int m_numerator{ 0 };
  int m_denominator{ 1 };

public:
  Fraction(int numerator=0, int denominator=1) : m_numerator{ numerator }, m_denominator{ denominator }
  {
    if (!m_denominator)
    {
      throw std::runtime_error( "Invalid denominator" );
    }
  }

  friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction)
  {
    out << fraction.m_numerator << '/' << fraction.m_denominator;

    return out;
  }
};

int main()
{
  std::cout << "Enter the numerator: ";
  int numerator{ };
  std::cin >> numerator;

  std::cout << "Enter the denominator: ";
  int denominator{ };
  std::cin >> denominator;

  try
  {
    std::cout << Fraction( numerator, denominator ) << '\n';
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what() << '\n';
  }

  return 0;
}
