# [3.4 — Basic debugging tactics](https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/)

## Debugging tactic #2: Validating your code flow

### Tip

When printing information for debugging purposes, use `std::cerr` instead of `std::cout`.
One reason for this is that `std::cout` may be buffered, which means there may be a pause between when you ask `std::cout` to output information and when it actually does.
If you output using `std::cout` and then your program crashes immediately afterward, `std::cout` may or may not have actually output yet.
This can mislead you about where the issue is.
On the other hand, `std::cerr` is unbuffered, which means anything you send to it will output immediately.
This helps ensure all debug output appears as soon as possible (at the cost of some performance, which we usually don't care about when debugging).

### Tip

When adding temporary debug statements, it can be helpful to not indent them.
This makes them easier to find for removal later.
