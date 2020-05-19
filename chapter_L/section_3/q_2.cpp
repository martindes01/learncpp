#include <iostream>
#include <string>

enum class Animal
{
  pig,
  chicken,
  goat,
  cat,
  dog,
  ostrich,
};

std::string getAnimalName(Animal animal)
{
  switch (animal)
  {
    case Animal::pig:
      return "pig";
    case Animal::chicken:
      return "chicken";
    case Animal::goat:
      return "goat";
    case Animal::cat:
      return "cat";
    case Animal::dog:
      return "dog";
    case Animal::ostrich:
      return "ostrich";
    default:
      return "Error: unknown animal type";
  }
}

void printNumberOfLegs(Animal animal)
{
  int legs{ };

  switch (animal)
  {
    case Animal::chicken:
    case Animal::ostrich:
      legs = 2;
      break;
    case Animal::cat:
    case Animal::dog:
    case Animal::goat:
    case Animal::pig:
      legs = 4;
      break;
    default:
      std::cout << "Error: unknown animal type\n";
      legs = 0;
      break;
  }

  std::cout << "A " << getAnimalName(animal) << " has " << legs << " legs.\n";
}

int main()
{
  printNumberOfLegs(Animal::cat);
  printNumberOfLegs(Animal::chicken);

  return 0;
}
