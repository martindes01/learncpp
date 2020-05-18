#include <iostream>
#include <string>

int main()
{
  std::string str{ "I saw a red car yesterday." };

  // replace "red" with "blue"
  // "red" is 3 characters starting at position 8
  str.replace(8, 3, "blue");

  std::cout << str << '\n'; // I saw a blue car yesterday.

  return 0;
}
