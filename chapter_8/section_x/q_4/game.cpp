#include "game.h"

#include "deck.h"
#include "player.h"

#include <iostream>
#include <limits>

namespace game
{
  // return whether player wishes to hit
  bool playerWantsHit()
  {
    char choice{ };
    while (true)
    {
      std::cout << "Hit (h) or stand (s)? ";
      std::cin >> choice;

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      switch (choice)
      {
        case 'h':
          return true;
        case 's':
          return false;
      }
    }
  }

  // allow player to perform hits
  // return whether player is still in contention
  bool playerTurn(Deck &deck, Player &player)
  {
    while (true)
    {
      std::cout << "You have: " << player.score() << '\n';

      if (player.isBust())
      {
        // player has lost
        // return false
        std::cout << "Oops!  You have exceeded " << maximumScore << ".\n";
        return false;
      }
      else
      {
        if (playerWantsHit())
        {
          // player chose to hit
          // draw a card
          player.drawCard(deck);
        }
        else
        {
          // player chose to stand
          // return true since player has not lost
          return true;
        }
      }
    }
  }

  // allow dealer to perform hits
  // return whether dealer is still in contention
  bool dealerTurn(Deck &deck, Player &dealer)
  {
    while (dealer.score() < minimumDealerScore)
    {
      // dealer must hit
      // draw a card
      dealer.drawCard(deck);
    }

    std::cout << "The dealer now has: " << dealer.score() << '\n';

    if (dealer.isBust())
    {
      // dealer has lost
      // return false
      std::cout << "Oops!  The dealer has exceeded " << maximumScore << ".\n";
      return false;
    }
    else
    {
      // dealer must stand
      // return true since dealer has not lost
      return true;
    }
  }

  // play a single game of blackjack
  // return whether player won
  bool playBlackjack(Deck &deck)
  {
    // dealer draws a card from the deck
    Player dealer{ };
    dealer.drawCard(deck);
    std::cout << "The dealer has: " << dealer.score() << '\n';

    // player draws two cards from the deck
    Player player{ };
    player.drawCard(deck);
    player.drawCard(deck);

    // take player turn
    if (playerTurn(deck, player))
    {
      // player still in contention
      // take dealer turn
      if (dealerTurn(deck, dealer))
      {
        // dealer still in contention
        // return whether player score is greater than dealer score
        // (tie considered as loss for player)
        return (player.score() > dealer.score());
      }
      else
      {
        // dealer lost (player won)
        return true;
      }
    }
    else
    {
      // player lost
      return false;
    }
  }
}
