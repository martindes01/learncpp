#include "card.h"

#include <iostream>

namespace game
{
  // return the value of the card
  // this is a custom value definition, not the rank
  int Card::value() const
  {
    if (m_rank >= Rank::TWO && m_rank <= Rank::TEN)
      return static_cast<int>(m_rank) + 2;

    switch (m_rank)
    {
    case Rank::JACK:
    case Rank::QUEEN:
    case Rank::KING:
      return 10;
    case Rank::ACE:
      return 11;
    default:
      return 0;
    }
  }

  // print two characters representing the card
  void Card::print() const
  {
    switch (m_rank)
    {
    case Rank::TWO:
      std::cout << '2';
      break;
    case Rank::THREE:
      std::cout << '3';
      break;
    case Rank::FOUR:
      std::cout << '4';
      break;
    case Rank::FIVE:
      std::cout << '5';
      break;
    case Rank::SIX:
      std::cout << '6';
      break;
    case Rank::SEVEN:
      std::cout << '7';
      break;
    case Rank::EIGHT:
      std::cout << '8';
      break;
    case Rank::NINE:
      std::cout << '9';
      break;
    case Rank::TEN:
      std::cout << 'T';
      break;
    case Rank::JACK:
      std::cout << 'J';
      break;
    case Rank::QUEEN:
      std::cout << 'Q';
      break;
    case Rank::KING:
      std::cout << 'K';
      break;
    case Rank::ACE:
      std::cout << 'A';
      break;
    default:
      std::cout << '?';
      break;
    }

    switch (m_suit)
    {
    case Suit::CLUBS:
      std::cout << 'C';
      break;
    case Suit::DIAMONDS:
      std::cout << 'D';
      break;
    case Suit::HEARTS:
      std::cout << 'H';
      break;
    case Suit::SPADES:
      std::cout << 'S';
      break;
    default:
      std::cout << '?';
      break;
    }
  }
}
