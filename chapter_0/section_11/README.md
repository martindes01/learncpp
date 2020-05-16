# [0.11 — Configuring your compiler: Warning and error levels](https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-warning-and-error-levels/)

### Best practice

Don’t let warnings pile up. Resolve them as you encounter them (as if they were errors).

### Best practice

Turn your warning levels up to the maximum, especially while you are learning.
It will help you identify possible issues.

## Increasing your warning levels

### For GCC/G++ users

Add the following flags to your command line: `-Wall -Weffc++ -Wextra -Wsign-conversion`

## Treat warnings as errors

### For GCC/G++ users

Add the following flag to your command line: `-Werror`
