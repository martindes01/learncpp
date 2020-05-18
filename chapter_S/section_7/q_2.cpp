#include <iostream>

struct Fraction
{
  int numerator{ };
  int denominator{ };
};

Fraction readFraction()
{
  Fraction frac{ };

  std::cout << "Enter an integer numerator: ";
  std::cin >> frac.numerator;

  std::cout << "Enter an integer denominator: ";
  std::cin >> frac.denominator;

  return frac;
}

Fraction multiplyFractions(Fraction frac1, Fraction frac2)
{
  return { frac1.numerator * frac2.numerator, frac1.denominator * frac2.denominator };
}

void printFraction(Fraction frac)
{
  std::cout << static_cast<double>(frac.numerator) / frac.denominator << '\n';
}

int main()
{
  Fraction frac1{ readFraction() };
  Fraction frac2{ readFraction() };

  printFraction(multiplyFractions(frac1, frac2));

  return 0;
}
