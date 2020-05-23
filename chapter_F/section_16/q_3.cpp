#include <cmath> // std::abs
#include <ctime> // std::time
#include <iostream>
#include <algorithm>
#include <random> // std::mt19937
#include <vector>

using list_t = std::vector<int>;

namespace random
{
  // define Mersenne Twister random number generator
  std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

constexpr int minRand{ 2 };
constexpr int maxRand{ 4 };
constexpr int maxError{ 4 };

// generate random integer between min and max, inclusive
int generateRandomInteger(const int min, const int max)
{
  return std::uniform_int_distribution{ min, max }(random::mersenne);
}

// generate list of answers
list_t generateAnswers(const int start, const int count, const int coeff)
{
  // define list of count items
  list_t answers(static_cast<list_t::size_type>(count));

  // set each answer to ((number++) ^ 2 * coeff)
  int number{ start };
  for (auto &answer : answers)
  {
    answer = number * number * coeff;
    ++number;
  }

  return answers;
}

// read guess from user
int readGuess()
{
  std::cout << "> ";
  int guess{ };
  std::cin >> guess;

  // assume input valid

  return guess;
}

// find guess in answers and remove it
// return true if guess found, false otherwise
bool findAndRemoveAnswer(list_t &answers, const int guess)
{
  auto answer{ std::find(answers.begin(), answers.end(), guess) };

  if (answer != answers.end())
  {
    // remove answer from list
    answers.erase(answer);

    return true;
  }
  else
  {
    return false;
  }
}

// find and return closest answer to guess
int findClosestAnswer(const list_t &answers, const int guess)
{
  // return value of element with least absolute difference from guess
  return *std::min_element(answers.begin(), answers.end(), [=](const int &a, const int &b){ return (std::abs(a - guess) < std::abs(b - guess)); });
}

// print success statement
void printSuccess(const list_t::size_type size)
{
  std::cout << "Nice!  ";
  if (size > 0)
  {
    std::cout << size << " number(s) left.\n";
  }
  else
  {
    std::cout << "You found all the numbers, good job!\n";
  }
}

// print failure statement
void printFailure(const list_t &answers, const int guess)
{
  std::cout << guess << " is wrong!";

  // get closest answer to guess
  int closestAnswer{ findClosestAnswer(answers, guess) };

  // check whether guess within maxError of closestAnswer
  if (std::abs(closestAnswer - guess) <= maxError)
  {
    std::cout << "  Try " << closestAnswer << " next time.\n";
  }
  else
  {
    std::cout << '\n';
  }
}

// play single round
// return true if answers remain, false otherwise
// return false if user lost
bool playRound(list_t &answers)
{
  // read guess from user
  int guess{ readGuess() };

  // search for guess in list of answers
  if (findAndRemoveAnswer(answers, guess))
  {
    // user was correct
    printSuccess(answers.size());

    // return whether any answers remain
    return !answers.empty();
  }
  else
  {
    // user was incorrect
    printFailure(answers, guess);

    // user lost
    return false;
  }
}

int main()
{
  std::cout << "Start where? ";
  int start{ };
  std::cin >> start;

  std::cout << "How many? ";
  int count{ };
  std::cin >> count;

  // assume input valid

  // generate random coefficient
  int coeff{ generateRandomInteger(minRand, maxRand) };

  // generate list of answers
  list_t answers{ generateAnswers(start, count, coeff) };

  // print prompt
  std::cout << "I generated " << count << " square numbers.  Do you know what each number is after multiplying it by " << coeff << "?\n";

  // play game until all answers removed or user loses
  while(playRound(answers))
  {
    ;
  }

  return 0;
}
