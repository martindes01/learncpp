#include <iostream>
#include <iterator>

int* find(int *begin, int *end, int value)
{
  // iterate through array using pointer arithmetic
  for (int *ptr{ begin }; ptr != end; ++ptr)
  {
    // return pointer to value if found in array
    if (*ptr == value)
    {
      return ptr;
    }
  }

  // value not found in array
  // return pointer to end of array
  return end;
}

int main()
{
  int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

  // search for first element with value 20
  int *found{ find(std::begin(arr), std::end(arr), 20) };

  // if an element with value 20 was found, print it
  if (found != std::end(arr))
    std::cout << *found << '\n';

  return 0;
}
