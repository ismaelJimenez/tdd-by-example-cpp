# Test-Driven Development in C++17 by Example

This project contains the code in C++17 to follow the exercises of the book Test-Driven Development by Example from Kent Beck.

## Building with Bazel

You can build and run your test:

```bash
my_workspace$ bazelisk test --test_output=all //c1/1:multiple_currency_test
```

## Strategies for quickly getting to green:
* Fake It: Return a constant and gradually replace constants with variables until you have the real code.
* Use Obvious Implementation: Type in the real implementation.
* Triangulation
