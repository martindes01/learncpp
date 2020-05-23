#include <cassert> // assert
#include <iostream>

// iterative implementation of binary search

// return index of target in sorted array if found, -1 otherwise
// assume array is sorted ascending
// min is the index of the lower bound of the search
// max is the index of the upper bound of the search
int binarySearch(const int *array, int target, int min, int max)
{
  // terminate if array does not exist
  assert(array);

  // loop until min index is greater than max index (termination condition)
  while (min <= max)
  {
    // check element at midpoint of the subarray
    // round down via integer division if even number of elements
    // int index{ (min + max) / 2 };

    // alternative midpoint calculation to avoid overflow from (min + max)
    int index{ min + (max - min) / 2 };

    if (array[index] > target)
    {
      // element at midpoint is greater than target
      // ignore upper half of subarray on next iteration
      max = index - 1;
    }
    else if (array[index] < target)
    {
      // element at midpoint is less than target
      // ignore lower half of subarray on next iteration
      min = index + 1;
    }
    else
    {
      // element at midpoint is equal to target
      // return index of midpoint
      return index;
    }
  }

  // element with target value not found
  // return sentinel value
  return -1;
}

int main()
{
  constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

  // test values to see if they produce the expected results
  constexpr int numTestValues{9};
  constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };

  // define expected results for each value
  int expectedValues[numTestValues]{-1, 0, 3, -1, -1, 8, -1, 13, -1};

  // loop through test values
  for (int count{ 0 }; count < numTestValues; ++count)
  {
    // search for test value in array
    int index{ binarySearch(array, testValues[count], 0, 14) };

    // check whether it matches the expected value
    if (index == expectedValues[count])
    {
      // binarySearch works
      std::cout << "Test value " << testValues[count] << " passed!\n";
    }
    else
    {
      // binarySearch does not work
      std::cout << "Test value " << testValues[count] << " failed.  There is something wrong with the code!\n";
    }
  }

  return 0;
}
