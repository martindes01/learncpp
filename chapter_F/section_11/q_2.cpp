#include <iostream>

// return the sum of the digits of a positive value
int sumDigits(const int value)
{
  if (value < 10)
  {
    // base case
    // assume value is positive
    return value;
  }
  else
  {
    // recurse with (value / 10)
    // (unit digit removed through integer division by 10)
    // add value of unit digit to sum
    // (non-unit digits removed through modulus division by 10)
    return sumDigits(value / 10) + value % 10;
  }
}

int main()
{
  int value{ 93427 };
  std::cout << "The sum of the digits in " << value << " is " << sumDigits(value) << ".\n";

  return 0;
}
