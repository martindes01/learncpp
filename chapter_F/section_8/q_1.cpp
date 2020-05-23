#include <functional> // std::function
#include <iostream>

using arithmeticFcn = std::function<int(int, int)>;

// return an integer from the user
int readInteger()
{
  std::cout << "Enter an integer: ";
  int x{ };
  std::cin >> x;

  // input validation omitted

  return x;
}

// return an operator character from the user
char readOperator()
{
  char op{ };

  do
  {
    std::cout << "Enter an operator (+, -, *, or /): ";
    std::cin >> op;

    // extraneous input validation omitted
  } while ((op != '+') && (op != '-') && (op != '*') && (op != '/'));

  return op;
}

// return the sum of two integers
int add(const int x, const int y)
{
  return x + y;
}

// return the difference between two integers
int subtract(const int x, const int y)
{
  return x - y;
}

// return the product of two integers
int multiply(const int x, const int y)
{
  return x * y;
}

// return the integer part of the quotient of two integers
int divide(const int x, const int y)
{
  // use integer division
  return x / y;
}

// return a pointer to the arithmetic function represented by an operator character
arithmeticFcn getArithmeticFunction(const char op)
{
  switch (op)
  {
    case '+':
      return add;
    case '-':
      return subtract;
    case '*':
      return multiply;
    case '/':
      return divide;
    default:
      // return nullptr if passed invalid operator character
      return nullptr;
  }
}

int main()
{
  int x{ readInteger() };
  char op{ readOperator() };
  int y{ readInteger() };

  // get pointer to arithmetic function represented by op
  arithmeticFcn fcn{ getArithmeticFunction(op) };

  // check that fcn is valid pointer
  if (fcn)
  {
    // print result
    std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x, y) << '\n';
  }
  else
  {
    // invalid pointer
    std::cout << "Invalid operation.\n";
  }

  return 0;
}
