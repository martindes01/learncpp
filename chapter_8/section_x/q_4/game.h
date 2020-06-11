#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"

namespace game
{
  inline constexpr int maximumScore{ 21 };
  inline constexpr int minimumDealerScore{ 17 };

  bool playerWantsHit();

  bool playerTurn(Deck &deck, Player &player);

  bool dealerTurn(Deck &deck, Player &dealer);

  bool playBlackjack(Deck &deck);
}

#endif
