#include <iostream>

void print(const char *string)
{
  while (*string != '\0') {
    std::cout << *string;
    ++string;
  }
}

int main()
{
  print("Hello, world!");

  return 0;
}
