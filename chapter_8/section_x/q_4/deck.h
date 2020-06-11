#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <array>

namespace game
{
  class Deck
  {
  public:
    using deck_t = std::array<Card, static_cast<int>(Card::Rank::TOTAL_RANKS) * static_cast<int>(Card::Suit::TOTAL_SUITS)>;
    using index_t = deck_t::size_type;

  private:
    deck_t m_deck{ };
    index_t m_cardIndex{ 0 };

  public:
    Deck()
    {
      index_t index{ 0 };
      index_t totalRanks{ static_cast<Deck::index_t>(Card::Rank::TOTAL_RANKS) };
      index_t totalSuits{ static_cast<Deck::index_t>(Card::Suit::TOTAL_SUITS) };

      for (index_t suit{ 0 }; suit < totalSuits; ++suit)
      {
        for (index_t rank{ 0 }; rank < totalRanks; ++rank)
        {
          m_deck[index] = Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
          ++index;
        }
      }
    }

    void print() const;

    void shuffle();

    const Card& dealCard();
  };
}

#endif
