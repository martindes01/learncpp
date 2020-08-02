#include <iostream>

template <typename T>
class Pair1
{
private:
  T m_first{ };
  T m_second{ };

public:
  Pair1(const T &first, const T &second) : m_first{ first }, m_second{ second } { }

  const T& first() const
  {
    return m_first;
  }

  const T& second() const
  {
    return m_second;
  }
};

int main()
{
  Pair1<int> p1{ 5, 8 };
  std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

  const Pair1<double> p2{ 2.3, 4.5 };
  std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

  return 0;
}
