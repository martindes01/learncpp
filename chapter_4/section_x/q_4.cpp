#include "physics.h"
#include <iostream>

double readTowerHeight()
{
  std::cout << "Enter the height of the tower in metres: ";
  double height{ };
  std::cin >> height;

  return height;
}

int main()
{
  double initHeight{ readTowerHeight() };

  physics::calcAndPrintHeight(initHeight, 0);
  physics::calcAndPrintHeight(initHeight, 1);
  physics::calcAndPrintHeight(initHeight, 2);
  physics::calcAndPrintHeight(initHeight, 3);
  physics::calcAndPrintHeight(initHeight, 4);
  physics::calcAndPrintHeight(initHeight, 5);

  return 0;
}
