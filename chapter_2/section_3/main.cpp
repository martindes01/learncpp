// g++ -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror main.cpp -o main

#include <iostream>

int doubleNumber(int x)
{
  return x * 2;
}

int main()
{
  int x{ };
  std::cout << "Enter an integer: ";
  std::cin >> x;

  std::cout << "Double " << x << " is " << doubleNumber(x) << ".\n";

  return 0;
}
