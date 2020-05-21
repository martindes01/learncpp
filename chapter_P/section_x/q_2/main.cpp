#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student
{
  std::string name{ };
  int grade{ };
};

// return number of students to be entered
int readTotalStudents()
{
  int totalStudents{ };
  do
  {
    // assume input extraction succeeds
    std::cout << "How many students do you wish to enter? ";
    std::cin >> totalStudents;
  } while (totalStudents <= 0);

  return totalStudents;
}

// enter students into vector
void enterStudents(std::vector<Student> &students)
{
  int index{ 1 };

  for (auto &student : students)
  {
    // assume name does not contain spaces
    std::cout << "Name #" << index << ": ";
    std::cin >> student.name;

    // assume input extraction succeeds
    std::cout << "Grade #" << index << ": ";
    std::cin >> student.grade;

    // omit grade validation

    ++index;
  }
}

// return true if first student has higher or equal grade
// (return true if first argument should be ordered before second)
bool highestGradeFirst(const Student &a, const Student &b)
{
  return (a.grade >= b.grade);
}

// print names and grades of students
void printStudents(const std::vector<Student> &students)
{
  for (const auto &student : students)
  {
    std::cout << student.name << " got a grade of " << student.grade << '\n';
  }
}

int main()
{
  // get number of students to be entered
  int totalStudents{ readTotalStudents() };

  // create vector of students to be entered
  std::vector<Student> students(totalStudents);

  // enter students into vector
  std::cout << "\nEnter the name and grade of each student.\n";
  enterStudents(students);

  // sort students by grade (highest first)
  std::sort(students.begin(), students.end(), highestGradeFirst);

  // print sorted students
  std::cout << "\nSorted by grade (highest first):\n";
  printStudents(students);

  return 0;
}
