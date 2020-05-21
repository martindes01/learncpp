#include <iostream>
#include <iterator>

int main()
{
  int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

  for (int index{ 0 }, length{ std::size(array) }; index < length; ++index)
  {
    std::cout << array[index] << ' ';
  }

  std::cout << '\n';

  return 0;
}
