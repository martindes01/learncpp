// g++ -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror main.cpp -o main

#include <iostream>

int main()
{
  std::cout << "Enter an integer: ";

  int num{ 0 };
  std::cin >> num;

  std::cout << "Double " << num << " is: " << num * 2 << '\n';
  std::cout << "Triple " << num << " is: " << num * 3 << '\n';

  return 0;
}
