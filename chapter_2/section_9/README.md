# [2.9 — Naming collisions and an introduction to namespaces](https://www.learncpp.com/cpp-tutorial/2-9-naming-collisions-and-an-introduction-to-namespaces/)

## What is a namespace?

### Key insight

A name declared in a namespace won't be mistaken for an identical name declared in another scope.

## The std namespace

### Key insight

When you use an identifier that is defined inside a namespace (such as the `std` namespace), you have to tell the compiler that the identifier lives inside the namespace.

## Explicit namespace qualifier std::

### Best practice

Use explicit namespace prefixes to access identifiers defined in a namespace.

### Warning

Avoid using directives (such as `using namespace std;`) at the top of your program.
They violate the reason why namespaces were added in the first place.
