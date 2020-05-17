#include "constants.h"
#include <iostream>

// g++ -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror main.cpp -o main

int main()
{
  std::cout << "Enter an integer radius: ";
  int radius{ };
  std::cin >> radius;

  double circumference{ 2.0 * radius * constants::pi };
  std::cout << "The circumference is: " << circumference << '\n';

  return 0;
}
