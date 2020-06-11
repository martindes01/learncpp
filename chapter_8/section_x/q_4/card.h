#ifndef CARD_H
#define CARD_H

namespace game
{

  class Card
  {
  public:
    enum class Rank
    {
      TWO,
      THREE,
      FOUR,
      FIVE,
      SIX,
      SEVEN,
      EIGHT,
      NINE,
      TEN,
      JACK,
      QUEEN,
      KING,
      ACE,

      TOTAL_RANKS,
    };

    enum class Suit
    {
      CLUBS,
      DIAMONDS,
      HEARTS,
      SPADES,

      TOTAL_SUITS,
    };

  private:
    Rank m_rank{ };
    Suit m_suit{ };

  public:
    Card() = default;

    Card(Rank rank, Suit suit) : m_rank{ rank }, m_suit{ suit } { }

    int value() const;

    void print() const;
  };
}

#endif
