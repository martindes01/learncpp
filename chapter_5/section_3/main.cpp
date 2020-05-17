#include <iostream>

int readInteger()
{
  std::cout << "Enter an integer: ";
  int x{ };
  std::cin >> x;

  return x;
}

bool isEven(int num)
{
  // if even, remainder is zero
  // if odd, remainder is non-zero
  // zero is false, non-zero is true
  // return logical complement
  return !(num % 2);
}

int main()
{
  int x{ readInteger() };

  if (isEven(x))
    std::cout << x << " is even\n";
  else
    std::cout << x << " is odd\n";

  return 0;
}
