#include <iostream>

int main()
{
  char c{ 'a' };

  while (c <= 'z')
  {
    std::cout << c << ' ' << static_cast<int>(c) << '\n';
    ++c;
  }

  return 0;
}
