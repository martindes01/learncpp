#include <iostream>

namespace animal
{
  enum Animal
  {
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,

    totalAnimals,
  };
}

int main()
{
  int legs[animal::totalAnimals]{ 2, 4, 4, 4, 2, 0 };

  std::cout << "An elephant has " << legs[animal::elephant] << " legs.\n";

  return 0;
}
