# [2.2 — Function return values](https://www.learncpp.com/cpp-tutorial/function-return-values/)

## Returning to main

### Best practice

Your `main` function should return `0` if the program ran normally.

### For advanced readers

The C++ standard only defines the meaning of 3 status codes: `0`, `EXIT_SUCCESS`, and `EXIT_FAILURE`.
`0` and `EXIT_SUCCESS` both mean the program executed successfully.
`EXIT_FAILURE` means the program did not execute successfully.

`EXIT_SUCCESS` and `EXIT_FAILURE` are defined in the `<cstdlib>` header:

```cpp
#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE

int main()
{
	return EXIT_SUCCESS;
}
```

If you want to maximize portability, you should only use `0` or `EXIT_SUCCESS` to indicate a successful termination, or `EXIT_FAILURE` to indicate an unsuccessful termination.

## A few additional notes about return values

### Best practice

Always explicitly provide a return value for any function that has a non-`void` return type.

### Warning

Failure to return a value from a function with a non-`void` return type (other than `main`) will result in undefined behavior.

## Reusing functions

### Best practice

Follow the DRY best practice: "don't repeat yourself".
If you need to do something more than once, consider how to modify your code to remove as much redundancy as possible.
Variables can be used to store the results of calculations that need to be used more than once (so we don't have to repeat the calculation).
Functions can be used to define a sequence of statements we want to execute more than once.
And loops (which we'll cover in a later chapter) can be used to execute a statement more than once.
