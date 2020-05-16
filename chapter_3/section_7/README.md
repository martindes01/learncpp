# [3.7 — Using an integrated debugger: Running and breakpoints](https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-running-and-breakpoints/)

## Set next statement

### Warning

The *set next statement* command will change the point of execution, but will not otherwise change the program state.
Your variables will retain whatever values they had before the jump.
As a result, jumping may cause your program to produce different values, results, or behaviors than it would otherwise.
Use this capability judiciously (especially jumping backwards).

### Warning

You should not use set next statement to change the point of execution to a different function.
This will result in undefined behavior, and likely a crash.
