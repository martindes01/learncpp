#include <iostream>
#include <memory> // std::make_unique

class Fraction
{
private:
  int m_numerator{ 0 };
  int m_denominator{ 1 };

public:
  Fraction(int numerator=0, int denominator=1) : m_numerator{ numerator }, m_denominator{ denominator } { }

  friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction)
  {
    out << fraction.m_numerator << '/' << fraction.m_denominator;

    return out;
  }
};

void printFraction(const Fraction* const ptr)
{
  if (ptr)
  {
    std::cout << *ptr << '\n';
  }
}

int main()
{
  auto ptr{ std::make_unique<Fraction>( 3, 5 ) };

  printFraction(ptr.get());

  return 0;
}
