# [1.6 — Uninitialized variables and undefined behavior](https://www.learncpp.com/cpp-tutorial/uninitialized-variables-and-undefined-behavior/)

## Uninitialized variables

Using the values of uninitialized variables can lead to unexpected results.
Consider the following short program:

```cpp
#include <iostream>

int main()
{
	// define an integer variable named x
	int x; // this variable is uninitialized because we haven't given it a value

	// print the value of x to the screen
	std::cout << x; // who knows what we'll get, because x is uninitialized

	return 0;
}
```

In this case, the computer will assign some unused memory to `x`.
It will then send the value residing in that memory location to `std::cout`, which will print the value (interpreted as an integer).
But what value will it print?
The answer is "who knows!", and the answer may (or may not) change every time you run the program.
Feel free to compile and run the program yourself (your computer won't explode).

## Undefined behavior

### Rule

Take care to avoid all situations that result in undefined behavior, such as using uninitialized variables.

## Quiz

1. What is an uninitialized variable? Why should you avoid using them?

   > An uninitialized variable is a variable that has not been given a value by the program (generally through initialization or assignment).
   Using the value stored in an uninitialized variable will result in undefined behavior.

1. What is undefined behavior, and what can happen if you do something that exhibits undefined behavior?

   > Undefined behavior is the result of executing code whose behavior is not well defined by the language.
   The result can be almost anything, including something that behaves correctly.
