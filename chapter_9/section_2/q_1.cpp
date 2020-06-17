#include <iostream>

class Fraction
{
private:
  int m_numerator{ };
  int m_denominator{ };

public:
  Fraction(int numerator=0, int denominator=1) : m_numerator{ numerator }, m_denominator{ denominator }
  {
    reduce();
  }

  // return greatest common divisor
  // static so can be called without object
  static int gcd(int a, int b)
  {
    return (b == 0) ? ((a > 0) ? a : -a) : gcd(b, a % b);
  }

  // reduce fraction by dividing numerator and denominator by greatest common divisor
  // fractions with a numerator or denominator of zero are not reduced
  void reduce()
  {
    if ((m_numerator != 0) && (m_denominator != 0))
    {
      int d{ gcd(m_numerator, m_denominator) };
      m_numerator /= d;
      m_denominator /= d;
    }
  }

  void print() const
  {
    std::cout << m_numerator << '/' << m_denominator << '\n';
  }

  friend Fraction operator*(int x, const Fraction &y);

  friend Fraction operator*(const Fraction &x, int y);

  friend Fraction operator*(const Fraction &x, const Fraction &y);
};

Fraction operator*(int x, const Fraction &y)
{
  return Fraction((x * y.m_numerator), y.m_denominator);
}

Fraction operator*(const Fraction &x, int y)
{
  return Fraction((x.m_numerator * y), x.m_denominator);
}

Fraction operator*(const Fraction &x, const Fraction &y)
{
  return Fraction((x.m_numerator * y.m_numerator), (x.m_denominator *  y.m_denominator));
}

int main()
{
  Fraction f1{ 2, 5 };
  f1.print();

  Fraction f2{ 3, 8 };
  f2.print();

  Fraction f3{ f1 * f2 };
  f3.print();

  Fraction f4{ f1 * 2 };
  f4.print();

  Fraction f5{ 2 * f2 };
  f5.print();

  Fraction f6{ Fraction( 1, 2 ) * Fraction( 2, 3 ) * Fraction( 3, 4 ) };
  f6.print();

  Fraction f7{ 0, 6 };
  f7.print();

  return 0;
}
