#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>

class FixedPoint2
{
public:
  using integral_t = std::int_least16_t;
  using fractional_t = std::int_least8_t;

private:
  integral_t m_integer{ };
  fractional_t m_fraction{ };

public:
  FixedPoint2(int integer=0, int fraction=0) : m_integer{ static_cast<integral_t>(integer) }, m_fraction{ static_cast<fractional_t>(fraction) }
  {
    // fractional part bound handling omitted

    // treat value as negative if either or both parts are negative
    // store both parts with the same sign for convenience

    // if integral part is negative, make sure fractional part is negative
    // do nothing if fractional part is zero
    if ((m_integer < 0) && (m_fraction > 0))
    {
      m_fraction = -m_fraction;
    }

    // if fractional part is negative, make sure integral part is negative
    // do nothing if integral part is zero
    if ((m_fraction < 0) && (m_integer > 0))
    {
      m_integer = -m_integer;
    }
  }

  FixedPoint2(double value) : m_integer{ static_cast<integral_t>(value) }, m_fraction{ static_cast<fractional_t>(round((value - m_integer) * 100)) } { }

  operator double() const;

  double operator-() const;

  friend bool operator==(const FixedPoint2 &a, const FixedPoint2 &b);

  friend FixedPoint2 operator+(const FixedPoint2 &a, const FixedPoint2 &b);

  friend std::istream& operator>>(std::istream &in, FixedPoint2 &fixedPoint2);

  // friend std::ostream& operator<<(std::ostream &out, const FixedPoint2 &fixedPoint2);
};

FixedPoint2::operator double() const
{
  return static_cast<double>(m_integer + m_fraction / 100.0);
}

double FixedPoint2::operator-() const
{
  return -static_cast<double>(*this);
}

bool operator==(const FixedPoint2 &a, const FixedPoint2 &b)
{
  return (static_cast<double>(a) == static_cast<double>(b));
}

FixedPoint2 operator+(const FixedPoint2 &a, const FixedPoint2 &b)
{
  return FixedPoint2( static_cast<double>(a) + static_cast<double>(b) );
}

std::istream& operator>>(std::istream &in, FixedPoint2 &fixedPoint2)
{
  double value{ };
  in >> value;

  fixedPoint2 = FixedPoint2( value );

  return in;
}

std::ostream& operator<<(std::ostream &out, const FixedPoint2 &fixedPoint2)
{
  out << static_cast<double>(fixedPoint2);

  return out;
}

void testAddition()
{
  std::cout << std::boolalpha;

  // both positive, no decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{1.23} == FixedPoint2{1.98}) << '\n';

  // both positive, with decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{1.50} == FixedPoint2{2.25}) << '\n';

  // both negative, no decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.23} == FixedPoint2{-1.98}) << '\n';

  // both negative, with decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.50} == FixedPoint2{-2.25}) << '\n';

  // second negative, no decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.23} == FixedPoint2{-0.48}) << '\n';

  // second negative, possible decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.50} == FixedPoint2{-0.75}) << '\n';

  // first negative, no decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.23} == FixedPoint2{0.48}) << '\n';

  // first negative, possible decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.50} == FixedPoint2{0.75}) << '\n';
}

int main()
{
  testAddition();

  FixedPoint2 a{ -0.48 };
  std::cout << a << '\n';

  std::cout << -a << '\n';

  std::cout << "Enter a number: "; // enter 5.678
  std::cin >> a;

  std::cout << "You entered: " << a << '\n';

  return 0;
}
