#include "random.h"

#include <random> // std::uniform_int_distribution

namespace random
{
  // return random integer between limits (inclusive)
  // uses Mersenne Twister algorithm
  int genRandInt(int min, int max)
  {
    std::uniform_int_distribution dist{min, max};
    return dist(mersenne);
  }
}
