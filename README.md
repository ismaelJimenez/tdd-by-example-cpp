You can build and run your test:

my_workspace$ bazelisk test --test_output=all //c1/1:multiple_currency_test

# Strategies for quickly getting to green:
* Fake It: Return a constant and gradually replace constants with variables until you have the real code.
* Use Obvious Implementation: Type in the real implementation.
* Triangulation
