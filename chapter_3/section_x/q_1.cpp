// g++ -g -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror q_1.cpp -o q_1

#include <iostream>

int readNumber()
{
  std::cout << "Please enter a number: ";
  int x{ };
  std::cin >> x;

  return x;
}

void writeAnswer(int x)
{
  std::cout << "The sum is: " << x;
}

int main()
{
  int x{ readNumber() };
  x = x + readNumber();
  writeAnswer(x);

  return 0;
}
