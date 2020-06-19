#ifndef MONSTER_H
#define MONSTER_H

#include "creature.h"
#include "random.h"

#include <array>
#include <random>
#include <string_view>

class Monster : public Creature
{
public:
  struct MonsterData
  {
    std::string_view name{ };
    char symbol{ };
    int health{ };
    int damage{ };
    int gold{ };
  };

  enum Type
  {
    DRAGON,
    ORC,
    SLIME,

    MAX_TYPES,
  };

private:
  static constexpr std::array<MonsterData, MAX_TYPES> monsterData
  {
    {
      { "dragon", 'D', 20, 4, 100 },
      { "orc", 'o', 4, 2, 25 },
      { "slime", 's', 1, 1, 10 }
    }
  };

public:
  Monster(Type type) : Creature{ monsterData[type].name.data(), monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold } { }

  static Monster getRandomMonster()
  {
    std::uniform_int_distribution dist{ 0, MAX_TYPES - 1 };

    return Monster{ static_cast<Type>(dist(random::mersenne)) };
  }
};

#endif
