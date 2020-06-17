#include <cassert>
#include <iostream>
#include <string>

class MyString
{
public:
  using index_t = std::string::size_type;

private:
  std::string m_string{ };

public:
  MyString(const std::string &string) : m_string{ string } { }

  std::string operator()(int startIndex, int length);
};

std::string MyString::operator()(int startIndex, int length)
{
  assert(((startIndex + length) <= static_cast<int>(m_string.length())) && "substring out of range");

  std::string substring{ };

  for (index_t index{ static_cast<index_t>(startIndex) }, end{ static_cast<index_t>(startIndex + length) }; index < end; ++index)
  {
    substring += m_string[index];
  }

  return substring;
}

int main()
{
  MyString string{ "Hello, world!" };
  std::cout << string(7, 5) << '\n';

  return 0;
}
