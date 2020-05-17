#include <bitset>
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits)
{
  // left shift bits by 1
  // right shift bits by 3 to shift msb to lsb
  // bitwise OR to combine results
  return ((bits << 1) | (bits >> 3));
}

int main()
{
  std::bitset<4> bits1{0b0001};
  std::cout << rotl(bits1) << '\n';

  std::bitset<4> bits2{0b1001};
  std::cout << rotl(bits2) << '\n';

  return 0;
}
