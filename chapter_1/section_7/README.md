# [1.7 — Keywords and naming identifiers](https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/)

## Identifier naming best practices

### Best practice

When working in an existing program, use the conventions of that program (even if they don't conform to modern best practices).
Use modern best practices when you're writing new programs.

## Quiz

1. Based on how you *should* name a variable, indicate whether each variable name is correct (follows convention), incorrect (does not follow convention), or invalid (will not compile), and why.

   ```cpp
   int sum; // assume it's obvious what we're summing
   ```

   > Correct.

   ```cpp
   int _apples;
   ```

   > Incorrect — variable names should not start with an underscore.

   ```cpp
   int VALUE;
   ```

   > Incorrect — variable names should start with a lower case letter.

   ```cpp
   int my variable name;
   ```

   > Invalid — variable names can not contain spaces.

   ```cpp
   int TotalCustomers;
   ```

   > Incorrect — variable names should start with a lower case letter.

   ```cpp
   int void;
   ```

   > Invalid — void is a keyword.

   ```cpp
   int numFruit;
   ```

   > Correct.

   ```cpp
   int 3some;
   ```

   > Invalid — variable names can not start with a number.

   ```cpp
   int meters_of_pipe;
   ```

   > Correct.
