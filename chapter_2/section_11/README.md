# [2.11 — Header files](https://www.learncpp.com/cpp-tutorial/header-files/)

## Headers, and their purpose

### Key insight

Header files allow us to put declarations in one location and then import them wherever we need them.
This can save a lot of typing in multi-file programs.

## Using standard library header files

### Key insight

When you `#include` a file, the content of the included file is inserted at the point of inclusion.
This provides a useful way to pull in declarations from another file.

### Best practice

Header files should generally not contain function and variable definitions, so as not to violate the one definition rule.
An exception is made for symbolic constants (which we cover in lesson [4.13 — Const, constexpr, and symbolic constants)](https://www.learncpp.com/cpp-tutorial/const-constexpr-and-symbolic-constants/).

## Writing your own header files

### Best practice

Use a `.h` suffix when naming your header files.

### Best practice

If a header file is paired with a code file (e.g. `add.h` with `add.cpp`), they should both have the same base name (`add`).

## Including a header in the corresponding source file

### Best practice

When writing a source file, include the corresponding header (If one exists), even if you don't need it yet.

## Angled brackets vs quotes

### Rule

Use angled brackets to include header files that come with the compiler.
Use double quotes to include any other header files.

## Why doesn't iostream have a .h extension?

### Best practice

When including a header file from the standard library, use the no extension version (without the `.h`) if it exists.
User-defined headers should still use a `.h` extension.

## Including header files from other directories

### For GCC/G++ users

Using `g++`, you can use the `-I` option to specify an alternate include directory.

```shell
g++ -o main -I/source/includes main.cpp
```

## Headers may include other headers

### Best practice

Each file should explicitly `#include` all of the header files it needs to compile.
Do not rely on headers included transitively from other headers.

## The #include order of header files

### Best practice

Order your `#includes` as follows: your own user-defined headers first, then 3rd party library headers, then standard library headers, with the headers in each section sorted alphabetically.
