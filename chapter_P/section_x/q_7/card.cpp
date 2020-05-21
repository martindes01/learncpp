#include "card.h"

#include "random.h"

#include <algorithm>
#include <iostream>

namespace card
{
  // return a full deck of cards
  deck_t createDeck()
  {
    deck_t deck{ };

    index_t index{ 0 };

    for (index_t suit{ 0 }; suit < totalSuits; ++suit)
    {
      for (index_t rank{ 0 }; rank < totalRanks; ++rank)
      {
        deck[index].rank = static_cast<Rank>(rank);
        deck[index].suit = static_cast<Suit>(suit);
        ++index;
      }
    }

    return deck;
  }

  // return the value of a card
  // this is a custom value definition, not the rank
  int getCardValue(const Card &card)
  {
    if (card.rank >= Rank::two && card.rank <= Rank::ten)
      return static_cast<int>(card.rank) + 2;

    switch (card.rank)
    {
      case Rank::jack:
      case Rank::queen:
      case Rank::king:
        return 10;
      case Rank::ace:
        return 11;
      default:
        return 0;
    }
  }

  // print two characters representing the card
  void printCard(const Card &card)
  {
    switch (card.rank)
    {
      case Rank::two:
        std::cout << '2';
        break;
      case Rank::three:
        std::cout << '3';
        break;
      case Rank::four:
        std::cout << '4';
        break;
      case Rank::five:
        std::cout << '5';
        break;
      case Rank::six:
        std::cout << '6';
        break;
      case Rank::seven:
        std::cout << '7';
        break;
      case Rank::eight:
        std::cout << '8';
        break;
      case Rank::nine:
        std::cout << '9';
        break;
      case Rank::ten:
        std::cout << 'T';
        break;
      case Rank::jack:
        std::cout << 'J';
        break;
      case Rank::queen:
        std::cout << 'Q';
        break;
      case Rank::king:
        std::cout << 'K';
        break;
      case Rank::ace:
        std::cout << 'A';
        break;
      default:
        std::cout << '?';
        break;
    }

    switch (card.suit)
    {
      case Suit::clubs:
        std::cout << 'C';
        break;
      case Suit::diamonds:
        std::cout << 'D';
        break;
      case Suit::hearts:
        std::cout << 'H';
        break;
      case Suit::spades:
        std::cout << 'S';
        break;
      default:
        std::cout << '?';
        break;
    }
  }

  // print the deck followed by a newline
  void printDeck(const deck_t &deck)
  {
    for (const auto &card : deck)
    {
      printCard(card);
      std::cout << ' ';
    }

    std::cout << '\n';
  }

  // shuffle the deck
  void shuffleDeck(deck_t &deck)
  {
    std::shuffle(deck.begin(), deck.end(), random::mersenne);
  }
}
