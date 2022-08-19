# Test-Driven Development in C++17 by Example

This project contains the code in C++17 to follow the exercises of the book Test-Driven Development by Example from Kent Beck.

## Building with Bazel

You can build and run your test:

```bash
my_workspace$ bazelisk test --test_output=all //c1/1:multiple_currency_test
```

## Static Analysis

```bash
bazelisk build //... --config clang-tidy
```

or

```bash
bazelisk build //c14/2:multiple_currency_test --config clang-tidy
```

## Strategies for quickly getting to green:
* Fake It: Return a constant and gradually replace constants with variables until you have the real code.
* Use Obvious Implementation: Type in the real implementation.
* Triangulation: Generalize code when we have two examples or more.

## Patterns
### Value Objects
Use objects as values. The values of the instance variables of the object never change once they have been set in the constructor.

One implication of Value Objects is that all operations must return a new object. Another implication is that Value Objects should implement equals().

```c++
  Dollar times(unsigned int multiplier)
  {
    return {amount * multiplier};
  }
```  