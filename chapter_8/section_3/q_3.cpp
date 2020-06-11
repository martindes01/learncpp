#include <array>
#include <cassert>
#include <iostream>

class Stack
{
public:
  using stack_t = std::array<int, 10>;
  using index_t = stack_t::size_type;

private:
  stack_t m_array{ };
  index_t m_nextIndex{ 0 };

public:
  // reset stack
  void reset()
  {
    m_nextIndex = 0;
  }

  // push value on stack
  // return false if stack already full, true otherwise
  bool push(int value)
  {
    if (m_nextIndex == m_array.size())
    {
      return false;
    }
    else
    {
      // push value and increment nextIndex
      m_array[m_nextIndex++] = value;
      return true;
    }
  }

  // pop value from stack and return it
  // terminate via assert if stack empty
  int pop()
  {
    assert((m_nextIndex > 0) && "Cannot pop from empty stack");

    // decrement nextIndex and pop value
    return m_array[--m_nextIndex];
  }

  // print stack values
  void print()
  {
    std::cout << "( ";

    for (index_t index{ 0 }; index < m_nextIndex; ++index)
    {
      std::cout << m_array[index] << ' ';
    }

    std::cout << ")\n";
  }
};

int main()
{
  Stack stack;

  stack.print();

  stack.push(5);
  stack.push(3);
  stack.push(8);
  stack.print();

  stack.pop();
  stack.print();

  stack.reset();
  stack.print();

  return 0;
}
