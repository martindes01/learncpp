// g++ -g -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror q_2.cpp -o q_2

#include <iostream>

int readNumber()
{
  std::cout << "Please enter a number: ";
  int x { };
  std::cin >> x;

  return x;
}

void writeAnswer(int x)
{
  std::cout << "The quotient is: " << x;
}

int main()
{
  int x{ readNumber() };
  int y{ readNumber() };

  writeAnswer(x / y);

  return 0;
}
