#include <algorithm> // std::swap
#include <iostream>
#include <iterator>

int main()
{
  int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
  int length{ static_cast<int>(std::size(array)) };

  // unoptimized ascending bubble sort

  for (int jjj{ 0 }; jjj < length; ++jjj)
  {
    for (int iii{ 0 }; iii < length - 1; ++iii)
    {
      if (array[iii] > array[iii + 1])
        std::swap(array[iii], array[iii + 1]);
    }
  }

  for (int iii{ 0 }; iii < length; ++iii)
  {
    std::cout << array[iii] << ' ';
  }

  std::cout << '\n';

  return 0;
}
