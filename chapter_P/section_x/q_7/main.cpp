#include "card.h"

#include <iostream>
#include <limits>

constexpr int maximumScore{ 21 };
constexpr int minimumDealerScore{ 17 };

struct Player
{
  int score{ };
};

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
bool playerTurn(const card::deck_t &deck, card::index_t &index, Player &player)
{
  while (true)
  {
    std::cout << "You have: " << player.score << '\n';

    if (player.score > maximumScore)
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
        player.score += card::getCardValue(deck[index++]);
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
bool dealerTurn(const card::deck_t &deck, card::index_t &index, Player &dealer)
{
  while (dealer.score < minimumDealerScore)
  {
    // dealer must hit
    // draw a card
    dealer.score += card::getCardValue(deck[index++]);
  }

  std::cout << "The dealer now has: " << dealer.score << '\n';

  if (dealer.score > maximumScore)
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
bool playBlackjack(const card::deck_t &deck)
{
  card::index_t index{ 0 };

  // dealer draws a card from the deck
  Player dealer{ card::getCardValue(deck[index++]) };
  std::cout << "The dealer has: " << dealer.score << '\n';

  // player draws two cards from the deck
  Player player{ card::getCardValue(deck[index]) + card::getCardValue(deck[index]) };
  index += 2;

  // take player turn
  if (playerTurn(deck, index, player))
  {
    // player still in contention
    // take dealer turn
    if (dealerTurn(deck, index, dealer))
    {
      // dealer still in contention
      // return whether player score is greater than dealer score
      // (tie considered as loss for player)
      return (player.score > dealer.score);
    }
    else
    {
      // dealer lost; therefore player won
      return true;
    }
  }
  else
  {
    // player lost
    return false;
  }
}

int main()
{
  // create and shuffle deck
  card::deck_t deck{ card::createDeck() };
  card::shuffleDeck(deck);

  // play a single game of blackjack
  std::cout << (playBlackjack(deck) ? "You win!\n" : "You lose!\n");

  return 0;
}
