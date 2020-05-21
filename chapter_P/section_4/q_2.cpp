#include <algorithm> // std::swap
#include <iostream>

int main()
{
  constexpr int length{ 5 };
  int array[length]{ 30, 50, 20, 10, 40 };

  // selection sort descending

  // iterate through array, except last element, which will already be sorted
  for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
  {
    // largestIndex is index of largest element encountered in this iteration
    int largestIndex{ startIndex };

    // look for larger element in rest of array
    for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
    {
      if (array[currentIndex] > array[largestIndex])
        largestIndex = currentIndex;
    }

    // swap start element with largest element
    std::swap(array[startIndex], array[largestIndex]);
  }

  for (int index{0}; index < length; ++index)
    std::cout << array[index] << ' ';

  std::cout << '\n';

  return 0;
}
