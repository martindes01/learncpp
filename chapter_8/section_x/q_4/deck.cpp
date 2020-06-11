#include "deck.h"

#include "card.h"
#include "random.h"

#include <algorithm>
#include <iostream>

namespace game
{
  // print the deck followed by a newline
  void Deck::print() const
  {
    for (const auto &card : m_deck)
    {
      card.print();
      std::cout << ' ';
    }

    std::cout << '\n';
  }

  // shuffle the deck
  void Deck::shuffle()
  {
    std::shuffle(m_deck.begin(), m_deck.end(), random::mersenne);
    m_cardIndex = 0;
  }

  // return the card at the current index and increment the index
  const Card& Deck::dealCard()
  {
    return m_deck[m_cardIndex++];
  }
}
