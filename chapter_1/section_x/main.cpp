// g++ -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror main.cpp -o main

#include <iostream>

int main()
{
  int x{ };
  std::cout << "Enter an integer: ";
  std::cin >> x;

  int y{ };
  std::cout << "Enter another integer: ";
  std::cin >> y;

  std::cout << x << " + " << y << " is " << x + y << ".\n";
  std::cout << x << " - " << y << " is " << x - y << ".\n";

  return 0;
}
