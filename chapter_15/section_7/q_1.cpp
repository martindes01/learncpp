#include <iostream>
#include <memory> // std::make_shared, std::weak_ptr

class Resource
{
public:
  std::weak_ptr<Resource> m_ptr{ };

  Resource() { std::cout << "Resource acquired\n"; }

  ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
  auto ptr1{ std::make_shared<Resource>() };

  ptr1->m_ptr = ptr1;

  return 0;
}
