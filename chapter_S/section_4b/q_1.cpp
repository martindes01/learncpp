#include <iostream>
#include <limits>
#include <string>

int main()
{
  std::cout << "Enter your full name: ";
  std::string name{ };
  std::getline(std::cin, name);

  std::cout << "Enter your age: ";
  int age{ };
  std::cin >> age;

  // ignore characters until newline is removed from stream
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  // std::cin.ignore(32767, '\n'); // 32767 is the largest signed value guaranteed to fit into a 2 byte integer on all platforms

  // static cast age to double to avoid integer division
  std::cout << "You've lived " << static_cast<double>(age) / name.length() << " years for each letter in your name.\n";

  return 0;
}
