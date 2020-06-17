#include <iostream>
#include <limits>

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

  friend std::istream& operator>>(std::istream &in, Fraction &fraction);

  friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
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

std::istream& operator>>(std::istream &in, Fraction &fraction)
{
  in >> fraction.m_numerator;
  in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
  in >> fraction.m_denominator;

  fraction.reduce();

  return in;
}

std::ostream& operator<<(std::ostream &out, const Fraction &fraction)
{
  out << fraction.m_numerator << '/' << fraction.m_denominator;

  return out;
}

int main()
{
  Fraction f1;
  std::cout << "Enter fraction 1: ";
  std::cin >> f1;

  Fraction f2;
  std::cout << "Enter fraction 2: ";
  std::cin >> f2;

  std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

  return 0;
}
