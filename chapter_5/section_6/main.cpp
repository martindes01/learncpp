#include "fltcmp.h"

#include <iomanip>
#include <iostream>
#include <limits>

int main()
{
  // set precision necessary to represent every double
  std::cout << std::setprecision(std::numeric_limits<double>::max_digits10);

  // print bool as string
  std::cout << std::boolalpha;

  // a is close to 1.0, but has rounding errors
  double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

  std::cout << "a is: " << a << '\n';
  std::cout << "a - 1.0 is: " << a - 1.0 << '\n';

  // compare "almost 0.0" to 0.0
  std::cout << "Is a - 1.0 approximately equal to 0.0? " << approximatelyEqualAbsRel(a - 1.0, 0.0, 1e-12, 1e-8) << '\n';

  return 0;
}
