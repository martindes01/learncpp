#include <cassert>
#include <iostream>

class IntArray
{
private:
  int *m_array{ };
  int m_size{ };

public:
  // default constructor
  IntArray(int size) : m_array{ new int[size]{ } }, m_size{ size } { }

  // deep copy member function
  void deepCopy(const IntArray &intArray);

  // copy constructor
  IntArray(const IntArray &intArray) : m_array{ nullptr }
  {
    deepCopy(intArray);
  }

  // destructor
  ~IntArray()
  {
    delete[] m_array;
  }

  // overloaded assignment operator
  IntArray& operator=(const IntArray &IntArray);

  // overloaded subscript operator
  int& operator[](int index)
  {
    assert((index >= 0) && (index < m_size) && "index out of range");

    return m_array[index];
  }

  // overloaded subscript operator for const IntArray
  const int& operator[](int index) const
  {
    assert((index >= 0) && (index < m_size) && "index out of range");

    return m_array[index];
  }

  // overloaded output operator
  friend std::ostream& operator<<(std::ostream &out, const IntArray &intArray);
};

void IntArray::deepCopy(const IntArray &intArray)
{
  // assume implicit object is initialized
  delete[] m_array;

  // assign new array of correct size
  m_array = new int[intArray.m_size]{ };

  // copy m_array
  if (intArray.m_array)
  {
    // copy elements
    for (int index{ 0 }; index < intArray.m_size; ++index)
    {
      m_array[index] = intArray.m_array[index];
    }
  }
  else
  {
    m_array = nullptr;
  }

  // copy m_size
  m_size = intArray.m_size;
}

IntArray& IntArray::operator=(const IntArray &intArray)
{
  // self-assignment guard
  if (this == &intArray)
    return *this;

  deepCopy(intArray);

  return *this;
}

std::ostream& operator<<(std::ostream &out, const IntArray &intArray)
{
  for (int index{ 0 }; index < intArray.m_size; ++index)
  {
    out << intArray.m_array[index] << ' ';
  }

  return out;
}

IntArray fillArray()
{
  IntArray a{ 5 };

  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;

  return a;
}

int main()
{
  IntArray a{ fillArray() };
  std::cout << a << '\n';

  auto &ref{ a };
  a = ref;

  IntArray b{ 1 };
  b = a;

  std::cout << b << '\n';

  return 0;
}
