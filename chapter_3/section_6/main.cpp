// g++ -g -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror main.cpp -o main

// gdb ./main
// gdb break main.cpp:main
// gdb run

#include <iostream>

void printValue(int value)
{
  std::cout << value << '\n';
}

int main()
{
  printValue(5);

  return 0;
}
