#ifndef RANDOM_H
#define RANDOM_H

#include <ctime>
#include <random>

namespace random
{
  // define Mersenne Twister random number generator
  std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

#endif
