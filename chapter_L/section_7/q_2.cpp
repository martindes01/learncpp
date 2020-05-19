#include <iostream>

int sumTo(int value)
{
  int sum{ };
  for (int count{ 1 }; count <= value; ++count)
    sum += count;

  return sum;
}

int main()
{
  std::cout << sumTo(5);

  return 0;
}
