#include <iostream>

bool passOrFail()
{
  // create static variable
  // initialized only on first call
  static int s_count{ 0 };

  // return true for first 3 calls, false thereafter
  // prefix increment s_count before comparison
  return (++s_count < 4);
}

int main()
{
  std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
  std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
  std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
  std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
  std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");

  return 0;
}
