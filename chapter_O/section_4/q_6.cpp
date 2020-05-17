#include <iostream>

// if num >= pow, print 1 and return difference
// else print 0 and return num
int printAndSubtract(int num, int pow)
{
  if (num >= pow)
  {
    std::cout << 1;
    return (num - pow);
  }
  else
  {
    std::cout << 0;
    return num;
  }
}

int main()
{
  std::cout << "Enter an integer between 0 and 255: ";
  int x{ };
  std::cin >> x;

  x = printAndSubtract(x, 128);
  x = printAndSubtract(x, 64);
  x = printAndSubtract(x, 32);
  x = printAndSubtract(x, 16);

  std::cout << ' ';

  x = printAndSubtract(x, 8);
  x = printAndSubtract(x, 4);
  x = printAndSubtract(x, 2);
  x = printAndSubtract(x, 1);

  std::cout << '\n';

  return 0;
}
