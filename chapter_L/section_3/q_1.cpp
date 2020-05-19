#include <iostream>

int calculate(int num1, int num2, char op)
{
  switch (op)
  {
    case '+':
      return num1 + num2;
    case '-':
      return num1 - num2;
    case '*':
      return num1 * num2;
    case '/':
      // integer division intended
      return num1 / num2;
    case '%':
      return num1 % num2;
    default:
      std::cout << "Error: invalid operator\n";
      return 0;
  }
}

int main()
{
  std::cout << "Enter an integer: ";
  int num1{ };
  std::cin >> num1;

  std::cout << "Enter another integer: ";
  int num2{ };
  std::cin >> num2;

  std::cout << "Enter an operator (+, -, *, /, or %): ";
  char op{ };
  std::cin >> op;

  std::cout << num1 << ' ' << op << ' ' << num2 << " = " << calculate(num1, num2, op) << '\n';

  return 0;
}
