#include <iostream>

int main()
{
  int outer{ 1 };

  // loop between 1 and 5
  while (outer <= 5)
  {
    int inner{ 5 };

    // loop between 5 and outer
    while (inner > outer)
    {
      std::cout << "  ";
      --inner;
    }

    // loop between outer and 1
    while (inner <= outer && inner > 0)
    {
      std::cout << inner-- << ' ';
    }

    // print a newline at the end of each row
    std::cout << '\n';
    ++outer;
  }

  return 0;
}
