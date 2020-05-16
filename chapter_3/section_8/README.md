# [3.8 — Using an integrated debugger: Watching variables](https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-watching-variables/)

### Warning

In case you are returning, make sure your project is compiled using a debug build configuration (see [0.9 — Configuring your compiler: Build configurations](https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-build-configurations/) for more information).
If you're compiling your project using a release configuration instead, the functionality of the debugger may not work correctly.

## The watch window can evaluate expressions too

### Warning

Identifiers in watched expressions will evaluate to their current values.
If you want to know what value an expression in your code is actually evaluating to, *run to cursor* to it first, so that all identifiers have the correct values.
