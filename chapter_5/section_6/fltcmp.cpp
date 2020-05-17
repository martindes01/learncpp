#include "fltcmp.h"
#include <algorithm> // std::max
#include <cmath> // std::abs

// return true if the difference between a and b is less than absEpsilon
// return true if the difference between a and b is within relEpsilon of the larger of a and b
// return false otherwise
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
  double diff{ std::abs(a - b) };

  // check absolute difference or fall back to Knuth's algorithm
  return ((diff <= absEpsilon) || (diff <= (std::max(std::abs(a), std::abs(b)) * relEpsilon)));
}
