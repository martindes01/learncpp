#include <iostream>

int main()
{
  std::cout << "Enter an integer: ";
  int smaller{ }; // smaller is created here
  std::cin >> smaller;

  std::cout << "Enter a larger integer: ";
  int larger{ }; // larger is created here
  std::cin >> larger;

  // swap values if sorted incorrectly
  if (smaller > larger)
  {
    std::cout << "Swapping the values\n";

    // create temporary variable to hold smaller
    int temp{ smaller }; // temp is created here

    // swap the values
    smaller = larger;
    larger = temp;
  } // temp is destroyed here

  std::cout << "The smaller value is " << smaller << '\n';
  std::cout << "The larger value is " << larger << '\n';

  return 0;
} // larger and smaller are destroyed here
