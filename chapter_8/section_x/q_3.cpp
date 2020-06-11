#include <array>
#include <cstdlib> // std::rand(), std::srand()
#include <ctime> // std::time()
#include <iostream>
#include <string>
#include <string_view>

class Monster
{
public:
  enum Type
  {
    DRAGON,
    GOBLIN,
    OGRE,
    ORC,
    SKELETON,
    TROLL,
    VAMPIRE,
    ZOMBIE,

    MAX_MONSTER_TYPES,
  };

private:
  Type m_type{ };
  std::string m_name{ };
  std::string m_roar{ };
  int m_hitPoints{ };

public:
  Monster(Type type, const std::string &name, const std::string &roar, int hitPoints) : m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints } { }

  // use string_view since strings known at compile-time
  std::string_view getTypeString() const
  {
    switch(m_type)
    {
    case DRAGON:
      return "dragon";

    case GOBLIN:
      return "goblin";

    case OGRE:
      return "ogre";

    case ORC:
      return "orc";

    case SKELETON:
      return "skeleton";

    case TROLL:
      return "troll";

    case VAMPIRE:
      return "vampire";

    case ZOMBIE:
      return "zombie";

    default:
      return "???";
    }
  }

  void print() const
  {
    std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
  }
};

class MonsterGenerator
{
public:
  // generate random number between min and max, inclusive
  // assume std::srand() has already been called
  // assume ((min - max) <= RAND_MAX)
  static int getRandomNumber(int min, int max)
  {
    // calculate fraction only once
    static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0)};

    // evenly distribute random number over range
    return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
  }

  static Monster generateMonster()
  {
    static std::array<std::string_view, 6> s_names{ "Alice", "Bob", "Charlie", "David", "Erin", "Frank" };

    static std::array<std::string_view, 6> s_roars{ "*Hello there*", "*I find your lack of faith disturbing*", "*The dark side of the force is a pathway to many abilities some consider to be ... unnatural*", "*Do. Or do not. There is no try.*", "*I've got a bad feeling about this*", "*It's a trap!*" };

    Monster::Type type{ static_cast<Monster::Type>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1)) };

    std::string name{ s_names[static_cast<std::size_t>(getRandomNumber(0, s_names.size() - 1))] };

    std::string roar{ s_roars[static_cast<std::size_t>(getRandomNumber(0, s_roars.size() - 1))] };

    int hitPoints{ getRandomNumber(1, 100) };

    return Monster( type, name, roar, hitPoints );
  }
};

int main()
{
  // set initial seed value to system clock
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  Monster m{ MonsterGenerator::generateMonster() };
  m.print();

  return 0;
}
