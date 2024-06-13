Summary
Throwing exceptions in constructors is a valid technique for handling errors that prevent an object from being properly constructed. However, there are alternatives that can provide clearer and more flexible error handling strategies:

Factory Functions: Encapsulate construction and error handling in a factory function.
Two-Phase Initialization: Separate initialization logic from the constructor.
Using std::optional: Use std::optional to indicate the possibility of construction failure without exceptions.
