#ifndef MONSTER_H
#define MONSTER_H

#include <string>

enum class MonsterType
{
  ogre,
  dragon,
  orc,
  giantSpider,
  slime,
};

struct Monster
{
  MonsterType type{ };
  std::string name{ };
  int health{ }; // consider default health
};

Monster readMonster();

std::string getMonsterTypeString(MonsterType type);

void printMonster(Monster monster);

#endif
