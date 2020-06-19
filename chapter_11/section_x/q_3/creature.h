#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature
{
protected:
  std::string m_name{ };
  char m_symbol{ };
  int m_health{ };
  int m_damage{ };
  int m_gold{ };

public:
  // default constructor
  Creature(const std::string &name, char symbol, int health, int damage, int gold) : m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage }, m_gold{ gold } { }

  // full set of getters
  const std::string& getName() const { return m_name; };
  char getSymbol() const { return m_symbol; };
  int getHealth() const { return m_health; };
  int getDamage() const { return m_damage; };
  int getGold() const { return m_gold; };

  // reduce health by specified amount
  void reduceHealth(int damage)
  {
    m_health -= damage;
  }

  // return true if health less than or equal to zero
  // return false otherwise
  bool isDead() const
  {
    return (m_health <= 0);
  }

  // add specified amount of gold
  void addGold(int gold)
  {
    m_gold += gold;
  }
};

#endif
