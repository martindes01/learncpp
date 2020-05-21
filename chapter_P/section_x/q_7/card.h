#ifndef CARD_H
#define CARD_H

#include <array>

namespace card
{
  // rank enumeration definition
  enum class Rank
  {
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace,

    totalRanks,
  };

  // suit enumeration definition
  enum class Suit
  {
    clubs,
    diamonds,
    hearts,
    spades,

    totalSuits,
  };

  // card struct definition
  struct Card
  {
    Rank rank{ };
    Suit suit{ };
  };

  // using type declarations

  using deck_t = std::array<Card, static_cast<int>(Rank::totalRanks) * static_cast<int>(Suit::totalSuits)>;

  using index_t = deck_t::size_type;

  // constants

  inline constexpr auto totalRanks{ static_cast<index_t>(Rank::totalRanks) };

  inline constexpr auto totalSuits{ static_cast<index_t>(Suit::totalSuits) };

  // function prototypes

  deck_t createDeck();

  int getCardValue(const Card &card);

  void printCard(const Card &card);

  void printDeck(const deck_t &deck);

  void shuffleDeck(deck_t &deck);
}

#endif
