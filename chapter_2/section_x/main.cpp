// g++ -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror main.cpp io.cpp -o main

// Include custom headers
#include "io.h"

int main()
{
  int x{ readNumber() };
  int y{ readNumber() };

  writeAnswer(x + y);

  return 0;
}
