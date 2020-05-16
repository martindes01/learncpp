// g++ -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror main.cpp -o main

#include <iostream>

int getValueFromUser()
{
  std::cout << "Enter an integer: ";
  int input{ };
  std::cin >> input;

  return input;
}

int main()
{
  int x{ getValueFromUser() };
  int y{ getValueFromUser() };

  std::cout << x << " + " << y << " = " << x + y << '\n';

  return 0;
}
