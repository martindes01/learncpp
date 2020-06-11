#include "deck.h"
#include "game.h"

#include <iostream>

int main()
{
  // create and shuffle deck
  game::Deck deck{ };
  deck.shuffle();

  // play a single game of blackjack
  std::cout << (game::playBlackjack(deck) ? "You win!\n" : "You lose!\n");

  return 0;
}
