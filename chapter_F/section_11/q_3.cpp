#include <iostream>

// print binary representation of a positive integer
void printBinary(const int decimal)
{
  // no recursion for base case (decimal <= 0)

  // recursion for all other cases
  if (decimal > 0)
  {
    // recurse with integer part of (decimal / 2) (integer division)
    printBinary(decimal / 2);
  }

  // print remainders in reverse order (after recursive call)
  // note that this will print 0 as the leftmost bit for the base case
  std::cout << decimal % 2;
}

int main()
{
  // set decimal to negative for loop condition
  int decimal{ -1 };

  // read positive integer from user
  do
  {
    std::cout << "Enter a positive integer: ";
    std::cin >> decimal;

    // additional input validation omitted
  } while (decimal < 0);

  printBinary(decimal);

  return 0;
}
