#include <iostream>

void swap(int &a, int &b)
{
  int temp{ a };
  a = b;
  b = temp;
}

int main()
{
  int a{ 1 };
  int b{ 2 };

  std::cout << "a is " << a << '\n';
  std::cout << "b is " << b << '\n';

  swap(a, b);

  std::cout << "a is " << a << '\n';
  std::cout << "b is " << b << '\n';

  if (a == 2 && b == 1)
    std::cout << "a and b were swapped\n";
  else
    std::cout << "a and b were not swapped\n";

  return 0;
}
