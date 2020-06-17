#include <cstdint>
#include <iostream>

class Average
{
public:
  using sum_t = std::int_least32_t;
  using count_t = std::int_least8_t;

private:
  sum_t m_sum{ 0 };
  count_t m_count{ 0 };

public:
  Average() = default;

  Average& operator+=(int addendum);

  friend std::ostream& operator<<(std::ostream &out, const Average &average);
};

Average& Average::operator+=(int addendum)
{
  m_sum += static_cast<sum_t>(addendum);
  ++m_count;

  return *this;
}

std::ostream& operator<<(std::ostream &out, const Average &average)
{
  // check whether count is zero
  // prevent divide by zero
  if (!average.m_count)
  {
    // count is zero; average must be zero
    out << 0;
  }
  else
  {
    // calculate and print average
    // cast to double to prevent integer division
    out << static_cast<double>(average.m_sum) / average.m_count;
  }

  return out;
}

int main()
{
  Average avg{ };

  avg += 4;
  std::cout << avg << '\n';

  avg += 8;
  std::cout << avg << '\n';

  avg += 24;
  std::cout << avg << '\n';

  avg += -10;
  std::cout << avg << '\n';

  (avg += 6) += 10;
  std::cout << avg << '\n';

  Average copy{ avg };
  std::cout << copy << '\n';

  return 0;
}
