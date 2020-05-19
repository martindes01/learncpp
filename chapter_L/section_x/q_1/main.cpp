#include "constants.h"

#include <iostream>

double readInitHeight()
{
  std::cout << "Enter the height of the tower in meters: ";
  double initHeight{ };
  std::cin >> initHeight;

  return initHeight;
}

double calcHeight(double initHeight, int seconds)
{
  // s = u * t - 0.5 * a * t ^ 2
  // h_1 = h_0 - (g * t^2) / 2
  return initHeight - 0.5 * myConstants::gravity * seconds * seconds;
}

void printHeight(double height, int seconds)
{
  if (height > 0.0)
    std::cout << "At " << seconds << " seconds, the ball is at height:\t" << height << " meters\n";
  else
    std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void printFall(double initHeight)
{
  int seconds{ 0 };
  double height{ };

  do
  {
    height = calcHeight(initHeight, seconds);
    printHeight(height, seconds);
    ++seconds;
  } while (height > 0.0);
}

int main()
{
  const double initHeight{ readInitHeight() };

  printFall(initHeight);

  return 0;
}
