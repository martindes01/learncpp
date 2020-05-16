# [2.8 — Programs with multiple code files](https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/)

## Adding files to your project

### Best practice

When you add new code files to your project, give them a `.cpp` extension.

### For GCC/G++ users

From the command line, you can create the additional file yourself, using your favorite editor, and give it a name.
When you compile your program, you'll need to include all of the relevant code files on the compile line.
For example: `g++ main.cpp add.cpp -o main`, where `main.cpp` and `add.cpp` are the names of your code files, and `main` is the name of the output file.
