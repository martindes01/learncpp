#include "game.h"

#include "input.h"
#include "random.h"

#include <iostream>

namespace game
{
  // return guess from user
  int readGuess()
  {
    int guess{ };

    // loop until input valid
    do
    {
      std::cin >> guess;

      // check whether input invalid
      if (input::reset())
      {
        std::cout << "Invalid guess.  Try again: ";

        // clear input buffer
        input::empty();
      }
      else
      {
        // clear input buffer
        input::empty();

        return guess;
      }
    } while (true);
  }

  // play single game
  void play()
  {
    std::cout << "Let's play a game.  I'm thinking of a number from " << minTarget << " to " << maxTarget << ".  You have " << totalGuesses << " tries to guess what it is.\n";

    // set random target
    int target{ random::genRandInt(minTarget, maxTarget) };

    // loop until target guessed or all guesses used
    for (int count{ 1 }; count <= totalGuesses; ++count)
    {
      std::cout << "Guess #" << count << ": ";
      int guess{ readGuess() };

      // compare guess to target
      if (guess > target)
        std::cout << "Your guess is too high.\n";
      else if (guess < target)
        std::cout << "Your guess is too low.\n";
      else
      {
        // guess and target must be equal
        std::cout << "Correct! You win!\n";
        return;
      }
    }

    std::cout << "Sorry, you lose.  The correct number was " << target << ".\n";
  }

  // return whether user wishes to play again
  bool again()
  {
    // loop until input valid
    while (true)
    {
      std::cout << "Would you like to play again (y/n)? ";
      char choice{ };
      std::cin >> choice;

      // clear input buffer
      input::empty();

      switch (choice)
      {
        case 'y':
          return true;
        case 'n':
          return false;
      }
    }
  }
}
