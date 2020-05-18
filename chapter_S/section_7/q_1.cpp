#include <iostream>

struct Advertising
{
  int countShownToday{ };
  double clickFraction{ };
  double earningPerClick{ };
};

Advertising readAdvertising()
{
  std::cout << "Enter number of ads: ";
  int countShownToday{ };
  std::cin >> countShownToday;

  std::cout << "Enter click-through fraction: ";
  double clickFraction{ };
  std::cin >> clickFraction;

  std::cout << "Enter average earning per ad: ";
  double earningPerClick{ };
  std::cin >> earningPerClick;

  return { countShownToday, clickFraction, earningPerClick };
}

void printAdvertising(Advertising ad)
{
  std::cout << "Number of ads show today:  " << ad.countShownToday << '\n';
  std::cout << "Click-through fraction:    " << ad.clickFraction << '\n';
  std::cout << "Average earning per click: " << ad.earningPerClick << '\n';

  std::cout << "Today's ad revenue:          " << ad.countShownToday * ad.clickFraction * ad.earningPerClick << '\n';
}

int main()
{
  Advertising ad{ readAdvertising() };

  printAdvertising(ad);

  return 0;
}
