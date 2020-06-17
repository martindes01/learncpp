#include <iostream>

class Cents
{
private:
  int m_cents{ };

public:
  Cents(int cents) : m_cents{ cents } { }

  friend bool operator>(const Cents &c1, const Cents &c2);
  friend bool operator>=(const Cents &c1, const Cents &c2);

  friend bool operator<=(const Cents &c1, const Cents &c2);
  friend bool operator<(const Cents &c1, const Cents &c2);
};

bool operator>(const Cents &c1, const Cents &c2)
{
  return (c1.m_cents > c2.m_cents);
}

bool operator>=(const Cents &c1, const Cents &c2)
{
  return (c1.m_cents >= c2.m_cents);
}

bool operator<=(const Cents &c1, const Cents &c2)
{
  return !(c1 > c2);
}

bool operator<(const Cents &c1, const Cents &c2)
{
  return !(c1 >= c2);
}

int main()
{
  Cents dime{ 10 };
  Cents nickel{ 5 };

  if (nickel > dime)
    std::cout << "a nickel is greater than a dime\n";
  if (nickel >= dime)
    std::cout << "a nickel is greater than or equal to a dime\n";
  if (nickel < dime)
    std::cout << "a nickel is less than a dime\n";
  if (nickel <= dime)
    std::cout << "a nickel is less than or equal to a dime\n";

  return 0;
}
