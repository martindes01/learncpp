# [1.2 — Comments](https://www.learncpp.com/cpp-tutorial/comments/)

## Multi-line comments

### Warning

Don't use multi-line comments inside other multi-line comments.
Wrapping single-line comments inside a multi-line comment is okay.

## Proper use of comments

### Best practice

Comment your code liberally, and write your comments as if speaking to someone who has no idea what the code does.
Don't assume you'll remember why you made specific choices.

## Commenting out code

### Tip

If you always use single line comments for your normal comments, then you can always use multi-line comments to comment out your code without conflict.
If you use multi-line comments to document your code, then commenting-out code using comments can become more challenging.

If you do need to comment out a code block that contains multi-line comments, you can also consider using the `#if 0` preprocessor directive, which we discuss in lesson [2.10 — Introduction to the preprocessor](https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/).
