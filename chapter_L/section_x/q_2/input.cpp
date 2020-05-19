#include "input.h"

#include <iostream>
#include <limits>

namespace input
{
  // remove extraneous input
  void empty()
  {
    // remove all input from buffer until a newline is removed
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  // reset flags if extraction failed
  // return whether extraction failed
  bool reset()
  {
    bool hasFailed{ std::cin.fail() };

    if (hasFailed)
      std::cin.clear();

    return hasFailed;
  }
}
