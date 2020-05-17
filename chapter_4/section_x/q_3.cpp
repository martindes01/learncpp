#include <iostream>

double readDouble()
{
  std::cout << "Enter a double value: ";
  double x{ };
  std::cin >> x;

  return x;
}

char readOperator()
{
  std::cout << "Enter one of the following: +, -, *, /: ";
  char op{ };
  std::cin >> op;

  return op;
}

void printResult(double num1, double num2, char op)
{
  if (op == '+')
    std::cout << num1 << " + " << num2 << " = " << num1 + num2 << '\n';
  else if (op == '-')
    std::cout << num1 << " - " << num2 << " = " << num1 - num2 << '\n';
  else if (op == '*')
    std::cout << num1 << " * " << num2 << " = " << num1 * num2 << '\n';
  else if (op == '/')
    std::cout << num1 << " / " << num2 << " = " << num1 / num2 << '\n';

  // print nothing if op invalid
}

int main()
{
  double x{ readDouble() };
  double y{ readDouble() };

  char op{ readOperator() };

  printResult(x, y, op);

  return 0;
}
