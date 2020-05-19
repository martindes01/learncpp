#include <iostream>

int main()
{
  for (int count{ 0 }; count <= 20; count += 2)
    std::cout << count << ' ';

  std::cout << '\n';

  return 0;
}
