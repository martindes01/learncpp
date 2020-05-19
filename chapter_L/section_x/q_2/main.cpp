#include "game.h"

#include <iostream>

int main()
{
  // play at least once until user does not wish to play again
  do
  {
    // play single game
    game::play();
  } while (game::again());

  std::cout << "Thank you for playing.\n";

  return 0;
}
