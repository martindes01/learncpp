#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"

namespace game
{
  class Player
  {
  private:
    int m_score{ };

  public:
    int score() const { return m_score; }

    void drawCard(Deck &deck);

    bool isBust() const;
  };
}

#endif
