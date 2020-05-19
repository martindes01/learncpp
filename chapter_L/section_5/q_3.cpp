#include <iostream>

int main()
{
  // loop between 5 and 1
  int outer{ 5 };
  while (outer > 0)
  {
    // loop between outer and 1
    int inner{ outer };
    while (inner > 0)
    {
      std::cout << inner-- << ' ';
    }

    // print a newline at the end of each row
    std::cout << '\n';
    --outer;
  }

  return 0;
}
