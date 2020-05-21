#include "card.h"

int main()
{
  card::deck_t deck{ card::createDeck() };

  card::printDeck(deck);

  card::shuffleDeck(deck);

  card::printDeck(deck);

  return 0;
}
