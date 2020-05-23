#include <iostream>

// return the factorial of an integer
int factorial(int value)
{
  if (value < 0)
  {
    // invalid case
    std::cout << "Error: the factorial of a negative is undefined.";
    return -1;
  }
  else if (value == 0)
  {
    // base case
    // 0! = 1
    return 1;
  }
  else
  {
    // recurse with (value - 1)
    // N! = N * (N - 1)!
    return value * factorial(value - 1);
  }
}

int main()
{
  for (int count{ 0 }; count < 7; ++count)
  {
    std::cout << factorial(count) << '\n';
  }

  return 0;
}
