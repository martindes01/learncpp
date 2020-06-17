#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
  std::string name{ };
  char grade{ };
};

class GradeMap
{
private:
  std::vector<StudentGrade> m_map{ };

public:
  char& operator[](const std::string &name)
  {
    // check whether student exists in map
    auto studentIterator
    {
      std::find_if(m_map.begin(), m_map.end(), [&](const StudentGrade &student){ return student.name == name; })
    };

    if (studentIterator != m_map.end())
    {
      // return reference to grade if student exists
      return studentIterator->grade;
    }
    else
    {
      // otherwise, add student to end of map and return reference to grade
      m_map.push_back({ name });
      return m_map.back().grade;
    }
  }
};

int main()
{
  GradeMap grades{ };

  grades["Joe"] = 'A';
  grades["Frank"] = 'B';

  std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
  std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

  return 0;
}
