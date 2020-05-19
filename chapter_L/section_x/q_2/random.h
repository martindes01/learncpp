#ifndef RANDOM_H
#define RANDOM_H

#include <ctime> // std::time
#include <random> // std::mt19937

namespace random
{
  // seed Mersenne Twister with time since epoch
  inline std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

  int genRandInt(int min, int max);
}

#endif
