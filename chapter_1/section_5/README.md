# [1.5 — Introduction to iostream: cout, cin, and endl](https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/)

## std::endl

### Tip

```cpp
#include <iostream> // for std::cout and std::endl

int main()
{
	std::cout << "Hi!" << std::endl; // std::endl will cause the cursor to move to the next line of the console
	std::cout << "My name is Alex." << std::endl;

	return 0;
}
```

In the above program, the second `std::endl` isn't technically necessary, since the program ends immediately afterward.
However, it serves two useful purposes:
First, it helps indicate that the line of output is a "complete thought".
Second, if we later want to add additional output statements, we don't have to modify the existing code.
We can just add them.

## std::endl vs '\n'

### Best practice

Prefer `'\n'` over std::endl when outputting text to the console.

### Warning

`'\n'` uses a backslash (as do all special characters in C++), not a forward slash.
Using a forward slash (e.g. `'/n'`) instead may result in unexpected behavior.

## std::cin

`std::cin` is another predefined variable that is defined in the `iostream` library.
Whereas `std::cout` prints data to the console using the insertion operator (`<<`), `std::cin` (which stands for "character input") reads input from keyboard using the extraction operator (`>>`).
The input must be stored in a variable to be used.

```cpp
#include <iostream>  // for std::cout and std::cin

int main()
{
	std::cout << "Enter a number: "; // ask user for a number
	int x{ }; // define variable x to hold user input (and zero-initialize it)
	std::cin >> x; // get number from keyboard and store it in variable x
	std::cout << "You entered " << x << '\n';
	return 0;
}
```

Try compiling this program and running it for yourself.
When you run the program, line 5 will print "Enter a number: ".
When the code gets to line 7, your program will wait for you to enter input.
Once you enter a number (and press enter), the number you enter will be assigned to variable `x`.
Finally, on line 8, the program will print "You entered " followed by the number you just entered.

### Best practice

There's some debate over whether it's necessary to initialize a variable immediately before you give it a user provided value via another source (e.g. `std::cin`), since the user-provided value will just overwrite the initialization value.
In line with our previous recommendation that variables should always be initialized, best practice is to initialize the variable first.
