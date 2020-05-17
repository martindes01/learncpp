#include "constants.h"
#include "physics.h"
#include <iostream>

namespace physics
{
  double calcHeight(double initHeight, int seconds)
  {
    return initHeight - constants::gravity * seconds * seconds / 2.0;
  }

  void printHeight(double height, int seconds)
  {
    if (height > 0.0)
      std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " metres\n";
    else
      std::cout << "At " << seconds << " seconds, the ball is on the ground\n";
  }

  void calcAndPrintHeight(double initHeight, int seconds)
  {
    double height{ calcHeight(initHeight, seconds) };
    printHeight(height, seconds);
  }
}
