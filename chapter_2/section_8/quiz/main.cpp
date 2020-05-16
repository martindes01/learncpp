// g++ -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror main.cpp input.cpp -o main

#include <iostream>

int getInteger(); // forward declaration for function getInteger

int main()
{
  int x{ getInteger() };
  int y{ getInteger() };

  std::cout << x << " + " << y << " is " << x + y << '\n';
  return 0;
}
