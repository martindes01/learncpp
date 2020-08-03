#include <iostream>
#include <memory> // std::make_shared, std::shared_pointer

// assume Something is a class that can throw an exception
class Something { };

void doSomething(std::shared_ptr<Something> &&a, std::shared_ptr<Something> &&b) { }

int main()
{
  doSomething(std::make_shared<Something>(), std::make_shared<Something>());

  return 0;
}
