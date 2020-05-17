#include <bitset>
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits)
{
  bool msb = bits.test(3);

  // left shift bits
  bits <<= 1;

  // if MSB was 1, set LSB
  if (msb)
    bits.set(0);

  return bits;
}

int main()
{
  std::bitset<4> bits1{0b0001};
  std::cout << rotl(bits1) << '\n';

  std::bitset<4> bits2{0b1001};
  std::cout << rotl(bits2) << '\n';

  return 0;
}
