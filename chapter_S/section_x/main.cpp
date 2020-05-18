#include "monster.h"

#include <iostream>

int main()
{
  Monster ogre{ MonsterType::ogre, "Torg", 145 };
  Monster slime{ MonsterType::slime, "Blurp", 23 };

  printMonster(ogre);
  printMonster(slime);

  std::cout << '\n';

  Monster monster1{ readMonster() };
  printMonster(monster1);

  std::cout << '\n';

  Monster monster2{ readMonster() };
  printMonster(monster2);

  return 0;
}
