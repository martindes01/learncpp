#include <iostream>
#include <iterator>

// check for input failure and empty buffer
void cleanInput()
{
  if (std::cin.fail())
    std::cin.clear();

  std::cin.ignore(32767, '\n');
}

// return integer between 1 and 9, inclusive, from user
int readValue()
{
  int value{ };

  do
  {
    std::cout << "Enter an integer between 1 and 9, inclusive: ";
    std::cin >> value;

    // check for input failure and empty buffer
    cleanInput();
  } while ((value < 1) || (value > 9));

  return value;
}

int main()
{
  int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

  int value{ readValue() };
  int indexOfValue{ };

  // print array while searching for value
  for (int index{ 0 }, length{ std::size(array) }; index < length; ++index)
  {
    std::cout << array[index] << ' ';

    if (array[index] == value)
      indexOfValue = index;
  }

  std::cout << '\n';

  std::cout << "The index of " << value << " is " << indexOfValue << ".\n";

  return 0;
}
