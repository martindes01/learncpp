# [1.9 — Introduction to expressions](https://www.learncpp.com/cpp-tutorial/introduction-to-expressions/)

## Expressions

### Key insight

Wherever you can use a single value in C++, you can use an expression instead, and the compiler will resolve the expression down to a single value.

## Expression statements

### Rule

Values calculated in an expression are discarded at the end of the expression.

## Quiz

1. What is the difference between a statement and an expression?

   > Statements are used when we want the program to perform an action.
   Expressions are used when we want the program to calculate a value.

1. Indicate whether each of the following lines are *statements that do not contain expressions*, *statements that contain expressions*, or are *expression statements*.

   a)

      ```cpp
      int x;
      ```

      > Statement does not contain an expression (this is just a variable definition)

   b)

      ```cpp
      int x = 5;
      ```

      > Statement contains an expression (The right hand side of the equals side is an expression containing a single value, but the rest of the statement isn't an expression)

   c)

      ```cpp
      x = 5;
      ```

      > Expression statement (the entire statement is an expression, terminated by a semicolon)

   d) Extra credit:

      ```cpp
      std::cout << x; // Hint: operator<< is a binary operator.
      ```

      > If operator`<<` is a binary operator, then `std::cout` must be the left-hand operand, and `x` must be the right-hand operand.
      Since that's the entire statement, this must be an expression statement.

1. Determine what values the following program outputs.
   Do not compile this program.
   Just work through it line by line in your head.

   ```cpp
   #include <iostream>

   int main()
   {
   	std::cout << 2 + 3 << '\n';

   	int x{ 6 };
   	int y{ x - 2 };
   	std::cout << y << '\n';

   	int z{ 0 };
   	z = x;
   	std::cout << z - x << '\n';

   	return 0;
   }
   ```

   > `5`

   > `4`

   > `0`
