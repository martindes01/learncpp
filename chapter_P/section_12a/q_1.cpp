#include <iostream>
#include <string>
#include <string_view>

int main()
{
  std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

  std::cout << "Enter a name: ";
  std::string queryName{ };
  std::cin >> queryName;

  bool found{ false };
  for (auto name : names)
  {
    if (name == queryName)
    {
      found = true;
      break;
    }
  }

  if (found)
    std::cout << queryName << " was found.\n";
  else
    std::cout << queryName << " was not found.\n";

  return 0;
}
