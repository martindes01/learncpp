# [3.6 — Using an integrated debugger: Stepping](https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-stepping/)

## The debugger

### Tip

Don't neglect learning to use a debugger.
As your programs get more complicated, the amount of time you spend learning to use the integrated debugger effectively will pale in comparison to amount of time you save finding and fixing issues.

### Warning

Before proceeding with this lesson (and subsequent lessons related to using a debugger), make sure your project is compiled using a debug build configuration (see [0.9 — Configuring your compiler: Build configurations](https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-build-configurations/) for more information).
If you're compiling your project using a release configuration instead, the functionality of the debugger may not work correctly.

## Step into

### For other compilers

If using a different IDE, you'll likely find the step into command under a Debug or Run menu.

### Warning

Because operator`<<` is implemented as a function, your IDE may step into the implementation of operator`<<` instead.

If this happens, you'll see your IDE open a new code file, and the arrow marker will move to the top of a function named operator`<<` (this is part of the standard library).
Close the code file that just opened, then find and execute step out debug command.
