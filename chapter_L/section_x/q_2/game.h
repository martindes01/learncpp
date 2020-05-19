#ifndef GAME_H
#define GAME_H

namespace game
{
  inline constexpr int minTarget{ 1 };
  inline constexpr int maxTarget{ 100 };
  inline constexpr int totalGuesses{ 7 };

  int readGuess();

  void play();

  bool again();
}

#endif
