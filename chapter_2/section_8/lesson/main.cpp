// g++ -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror main.cpp add.cpp -o main

#include <iostream>

int add(int x, int y); // needed so main.cpp knows that add() is a function declared elsewhere

int main()
{
  std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
  return 0;
}
