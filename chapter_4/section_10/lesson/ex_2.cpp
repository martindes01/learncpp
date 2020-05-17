#include <iostream>

bool isEqual(int x, int y)
{
  return (x == y);
}

int main()
{
  std::cout << "Enter an integer: ";
  int x{};
  std::cin >> x;

  std::cout << "Enter another integer: ";
  int y{};
  std::cin >> y;

  std::cout << std::boolalpha; // print bools as true or false

  if (isEqual(x, y))
    std::cout << x << " and " << y << " are equal\n";
  else
    std::cout << x << " and " << y << " are not equal\n";

  return 0;
}
