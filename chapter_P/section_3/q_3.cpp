#include <iostream>
#include <iterator> // std::size

int main()
{
  int scores[]{ 84, 92, 76, 81, 56 };
  int numStudents{ static_cast<int>(std::size(scores)) };

  int indexOfMaxScore{ };

  for (int student{ 0 }; student < numStudents; ++student)
  {
    if (scores[student] > scores[indexOfMaxScore])
      indexOfMaxScore = student;
  }

  std::cout << "The best score was " << scores[indexOfMaxScore] << '\n';

  return 0;
}
