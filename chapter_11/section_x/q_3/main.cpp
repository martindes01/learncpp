#include "creature.h"
#include "monster.h"
#include "player.h"
#include "random.h"

#include <iostream>
#include <limits>

std::uniform_int_distribution coin{ 0, 1 };

// ignore input buffer up to and including next newline
void clearInputBuffer()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// return whether player wishes to run or fight
bool doesPlayerFight()
{
  while (true)
  {
    std::cout << "(R)un or (F)ight? ";
    char choice{ };
    std::cin >> choice;

    clearInputBuffer();

    switch (choice)
    {
    case 'R':
    case 'r':
      return false;

    case 'F':
    case 'f':
      return true;

    default:
      std::cout << "Invalid choice.\n";
      break;
    }
  }
}

// return whether player's flee is successful
bool isFleeSuccessful()
{
  // flip coin to determine success
  bool success = static_cast<bool>(coin(random::mersenne));

  if (success)
  {
    std::cout << "You successfully fled.\n";
    return true;
  }
  else
  {
    std::cout << "You failed to flee.\n";
    return false;
  }
}

// handle single attack on monster
void attackMonster(Player &player, Monster &monster)
{
  // player cannot attack if dead
  if (player.isDead())
    return;

  // player attacks monster
  monster.reduceHealth(player.getDamage());
  std::cout << "You hit the " << monster.getName() << " and dealt " << player.getDamage() << " damage.\n";

  // check whether player killed monster
  if (monster.isDead())
  {
    std::cout << "You killed the " << monster.getName() << ".\n";

    // player levels up
    player.levelUp();
    std::cout << "You are now at level " << player.getLevel() << ".\n";

    // player takes gold from monster
    player.addGold(monster.getGold());
    std::cout << "You found " << monster.getGold() << " gold.\n";
  }
}

// handle single attack on player
void attackPlayer(Player &player, Monster &monster)
{
  // monster cannot attack if dead
  if (monster.isDead())
    return;

  // monster attacks player
  player.reduceHealth(monster.getDamage());
  std::cout << "The " << monster.getName() << " hit you and dealt " << monster.getDamage() << " damage.\n";
}

// handle fight between player and a random monster
void fightMonster(Player &player)
{
  // create random monster
  Monster monster{ Monster::getRandomMonster() };
  std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

  // fight until player or monster dies
  while (!player.isDead() && !monster.isDead())
  {
    if (doesPlayerFight())
    {
      // player chose to fight

      // player attacks monster
      attackMonster(player, monster);

      // monster attacks player
      attackPlayer(player, monster);
    }
    else
    {
      // player did not choose to fight
      if (isFleeSuccessful())
      {
        // player fled successfully
        // end fight
        return;
      }
      else
      {
        // player failed to flee
        // monster attacks player
        attackPlayer(player, monster);
      }
    }
  }
}

int main()
{
  // get player name
  std::cout << "Enter your name: ";
  std::string name{ };
  std::cin >> name;

  clearInputBuffer();

  // create player
  Player player{ name };
  std::cout << "Welcome, " << player.getName() << ".\n";

  // fight monsters until player dies or wins
  while (!player.isDead() && !player.hasWon())
  {
    fightMonster(player);
  }

  // check outcome of game
  if (player.isDead())
  {
    std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
    std::cout << "Too bad you can't take it with you!\n";
  }
  else
  {
    std::cout << "Congratulations!  You have won the game with " << player.getGold() << " gold.\n";
  }

  return 0;
}
