#include "monster.h"

#include <iostream>
#include <limits>
#include <string>

Monster readMonster()
{
  std::cout << "Enter a monster type: ";
  int typeInt{ };
  std::cin >> typeInt;
  MonsterType type{ static_cast<MonsterType>(typeInt) };

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Enter a name: ";
  std::string name{ };
  std::getline(std::cin, name);

  std::cout << "Enter an integer health: ";
  int health{ };
  std::cin >> health;

  return { type, name, health };
}

std::string getMonsterTypeString(MonsterType type)
{
  if (type == MonsterType::ogre)
    return "Ogre";
  else if (type == MonsterType::dragon)
    return "Dragon";
  else if (type == MonsterType::orc)
    return "Orc";
  else if (type == MonsterType::giantSpider)
    return "Giant Spider";
  else if (type == MonsterType::slime)
    return "Slime";
  else
    // return "???"" if a new monster type is added but not implemented here
    return "???";
}

void printMonster(Monster monster)
{
  std::cout << "This " << getMonsterTypeString(monster.type) << " is named " << monster.name << " and has " << monster.health << " health.\n";
}
