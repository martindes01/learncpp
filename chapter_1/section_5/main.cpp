// g++ -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror main.cpp -o main

#include <iostream>

int main()
{
  std::cout << "Enter a number: "; // ask user for a number
  int x{ }; // define variable x to hold user input (and zero-initialize it)
  std::cin >> x; // get number from keyboard and store it in variable x
  std::cout << "You entered " << x << '\n';
  return 0;
}
