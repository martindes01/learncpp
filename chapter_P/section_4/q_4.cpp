#include <algorithm> // std::swap
#include <iostream>
#include <iterator>

int main()
{
  int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
  int length{ static_cast<int>(std::size(array)) };

  // optimized ascending bubble sort

  for (int jjj{ 0 }; jjj < length; ++jjj)
  {
    // track number of swaps for each outer iteration
    bool hasSwapped{ false };

    // subtract jjj from (length - 1) to prevent checking elements that have already bubbled up
    for (int iii{ 0 }; iii < length - 1 - jjj; ++iii)
    {
      if (array[iii] > array[iii + 1])
      {
        std::swap(array[iii], array[iii + 1]);
        hasSwapped = true;
      }
    }

    // break if no swaps occurred
    if (!hasSwapped)
      break;
  }

  // print sorted array
  for (int iii{ 0 }; iii < length; ++iii)
  {
    std::cout << array[iii] << ' ';
  }

  std::cout << '\n';

  return 0;
}
