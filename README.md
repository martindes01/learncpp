# learncpp

## About

These are my notes and exercises following the comprehensive C++ tutorial at [learncpp.com](https://www.learncpp.com/).

## Getting Started

### Prerequisites

This project is intended for use with the [GCC](https://gcc.gnu.org/) C++ compiler (`g++`) and the [Make](https://www.gnu.org/software/make/) build automation tool, although any compiler that supports the C++17 standard can be used instead.

A brief guide to using [Visual Studio Code](https://code.visualstudio.com/) for C++ development can be found in the C++ article of its [documentation](https://code.visualstudio.com/docs).

### Installation

Simply clone the source from this repository.

```shell
git clone https://github.com/martindes01/learncpp.git
cd learncpp
```

### Files

The directory structure corresponds to the chapters and sections of [learncpp.com](https://www.learncpp.com/), as accessed during the period from 2020-05-16 through 2020-08-03.

Chapter | Title
---: | ---
0 | Introduction / Getting Started
1 | C++ Basics
2 | C++ Basics: Functions and Files
3 | Debugging C++ Programs
4 | Fundamental Data Types
5 | Operators
O | Bit Manipulation
6 | Object Scope and Conversions
S | Compound Types
L | Control Flow
P | Arrays, Strings, Pointers and References
F | Functions
8 | Basic Object-Oriented Programming
9 | Operator Overloading
10 | An Introduction to Object Relationships
11 | Inheritance
12 | Virtual Functions
13 | Templates
14 | Exceptions
15 | Move Semantics and Smart Pointers

## Usage

A makefile is provided with the source of each exercise.
Therefore, each exercise can be compiled by running `make` in its source directory.

For example, the number guessing game can be compiled from its source and run as follows.

```shell
cd chapter_L/section_x/q_2
make
./main
```

For many of the exercises, the compiled binary output is named `main`.

The makefile instructions for the first-time compilation of this example are equivalent to the following.

```shell
g++ -c -std=c++17 main.cpp -o main.o
g++ -c -std=c++17 game.cpp -o game.o
g++ -c -std=c++17 input.cpp -o input.o
g++ -c -std=c++17 random.cpp -o random.o
g++ -std=c++17 main.o game.o input.o random.o -o main
```

If no changes are to be made to the source of this example, it is sufficient to compile and link the source files without intermediate generation of the object files.

```shell
g++ -std=c++17 main.cpp game.cpp input.cpp random.cpp -o main
```

The files generated during compilation can be removed by executing the `clean` rule of the makefile.

```shell
make clean
```

## License

This project is distributed under the terms of the MIT License.
See [LICENSE](LICENSE) for more information.
