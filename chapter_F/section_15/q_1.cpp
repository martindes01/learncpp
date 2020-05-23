#include <algorithm> // std::max_element
#include <array>
// #include <functional> // std::function
#include <iostream>
#include <string>

struct Student
{
  std::string name{ };
  int points{ };
};

int main()
{
  std::array<Student, 8> arr
  { {
    { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 },
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 },
  } };

  Student *bestStudent{ std::max_element(arr.begin(), arr.end(), [](const Student &a, const Student &b){ return (a.points < b.points); }) };

  // alternatively

  // std::function hasFewerPoints
  // {
  //   [](const Student &a, const Student &b) -> bool
  //   {
  //     return (a.points < b.points);
  //   }
  // };

  // Student *bestStudent{ std::max_element(arr.begin(), arr.end(), hasFewerPoints) };

  std::cout << bestStudent->name << " is the best student.\n";

  return 0;
}
