#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"

#include <string>

class Player : public Creature
{
private:
  int m_level{ 1 };

public:
  // default constructor
  Player(const std::string &name) : Creature{ name, '@', 10, 1, 0 } { }

  // level getter
  int getLevel() const { return m_level; }

  // increase level and damage by one each
  void levelUp()
  {
    ++m_level;
    ++m_damage;
  }

  // return whether player has reached level 20
  bool hasWon() const
  {
    return (m_level >= 20);
  }
};

#endif
