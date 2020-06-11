#include <cstdint> // std::uint_fast8_t
#include <iostream>

class RGBA
{
public:
  using channel_t = std::uint_fast8_t;

private:
  channel_t m_red;
  channel_t m_green;
  channel_t m_blue;
  channel_t m_alpha;

public:
  RGBA(channel_t red=0, channel_t green=0, channel_t blue=0, channel_t alpha=255) : m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
  {
    // default constructor
  }

  void print()
  {
    std::cout << "r=" << static_cast<int>(m_red) << ' ';
    std::cout << "g=" << static_cast<int>(m_green) << ' ';
    std::cout << "b=" << static_cast<int>(m_blue) << ' ';
    std::cout << "a=" << static_cast<int>(m_alpha) << '\n';
  }
};

int main()
{
  RGBA teal{ 0, 127, 127 };
  teal.print();

  return 0;
}
