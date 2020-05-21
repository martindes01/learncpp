#include <array>
#include <iostream>
#include <numeric> // std::accumulate

namespace Item
{
  enum
  {
    healthPotion,
    torch,
    arrow,

    totalTypes,
  };
}

using inventory_t = std::array<int, Item::totalTypes>;

int countTotalItems(inventory_t inventory)
{
  return std::accumulate(inventory.begin(), inventory.end(), 0);
}

int main()
{
  inventory_t inventory{ 2, 5, 10 };

  std::cout << "You have " << countTotalItems(inventory) << " items in your inventory.\n";

  std::cout << "You have " << inventory[Item::torch] << " torches in your inventory.\n";

  return 0;
}
