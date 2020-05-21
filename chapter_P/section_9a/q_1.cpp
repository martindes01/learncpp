#include <algorithm>
#include <iostream>
#include <limits>
#include <string>

// read number of names to be entered
int readLength()
{
  int length{ };

  // loop until input valid
  while (true)
  {
    std::cout << "How many names do you wish to enter? ";
    std::cin >> length;

    // input validation
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if (length > 0)
      {
        return length;
      }
    }
  }
}

// enter names from user into array
void enterNames(std::string *names, int length)
{
  for (int index{ 0 }; index < length; ++index)
  {
    std::cout << "Enter name #" << index + 1 << ": ";
    std::getline(std::cin, names[index]);
  }
}

void printNames(std::string *names, int length)
{
  for (int index{ 0 }; index < length; ++index)
  {
    std::cout << "Name #" << index + 1 << ": " << names[index] << '\n';
  }
}

int main()
{
  // get number of names to be entered
  int length{ readLength() };

  // allocate dynamic array of correct length
  std::string *names{ new std::string[length]{ } };

  // enter names from user into array
  // array decays into pointer to first element
  enterNames(names, length);

  // sort names
  // array decays into pointer to first element
  std::sort(names, names + length);

  std::cout << "\nHere is your sorted list:\n";

  // print names
  // array decays into pointer to first element
  printNames(names, length);

  // deallocate array
  delete[] names;

  // set array pointer to nullptr if not leaving scope immediately
  // names = nullptr;

  return 0;
}
