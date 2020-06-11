#include "game.h"
#include "card.h"
#include "deck.h"

namespace game
{
  void Player::drawCard(Deck &deck)
  {
    m_score += deck.dealCard().value();
  }

  bool Player::isBust() const
  {
    return (m_score > game::maximumScore);
  }
}
