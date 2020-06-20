# cpp-rng-utils
A library for simpler-to-use RNG in C++.

This library encapsulates the standard C++ random generators and makes it possible to generate random numbers in just one statement, from anywhere in your code. It is **not** thread-safe, which means that the behaviour is not defined in case you attempt to call library functions from 2 different threads.
I also added functions to generate random vectors/points (represented by the sf::Vector2f class from SFML). For example, you can generate a random unit vector or a random point inside a circle.
If you are not interested by the SFML part/are too lazy to link it, you can simply #undef a preprocessor definition and this part will not be compiled.
