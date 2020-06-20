#include <iostream>
#include <string>
#include <string_view>

class Animal
{
protected:
  std::string m_name{ };
  std::string_view m_sound{ };

  Animal(const std::string &name, std::string_view sound) : m_name{ name }, m_sound{ sound } { }

public:
  const std::string& getName() const { return m_name; }

  std::string_view speak() const { return m_sound; }
};

class Cat : public Animal
{
public:
  Cat(const std::string &name) : Animal{ name, "Meow" } { }
};

class Dog : public Animal
{
public:
  Dog(const std::string &name) : Animal{ name, "Woof" } { }
};

int main()
{
  Cat fred{ "Fred" };
  Cat misty{ "Misty" };
  Cat zeke{ "Zeke" };

  Dog garbo{ "Garbo" };
  Dog pooky{ "Pooky" };
  Dog truffle{ "Truffle" };

  // initialise array of pointers to Animals
  // set pointers to Cat and Dog objects
  Animal *animals[]{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

  for (const auto animal : animals)
    std::cout << animal->getName() << " says " << animal->speak() << '\n';

  return 0;
}
