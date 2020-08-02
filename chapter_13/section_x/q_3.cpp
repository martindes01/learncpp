#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair2
{
private:
  T1 m_first{ };
  T2 m_second{ };

public:
  Pair2(const T1 &first, const T2 &second) : m_first{ first }, m_second{ second } { }

  const T1& first() const
  {
    return m_first;
  }

  const T2& second() const
  {
    return m_second;
  }
};

template <typename T>
class StringValuePair : public Pair2<std::string, T>
{
public:
  StringValuePair(const std::string &first, const T &second) : Pair2<std::string, T>(first, second) { }
};

int main()
{
  StringValuePair<int> svp{ "Hello", 5 };
  std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

  return 0;
}
