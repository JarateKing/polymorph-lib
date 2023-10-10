## Polymorph-lib: A Compile-Time Randomization Library

Polymorph-lib is a header-only library designed to provide compile-time randomization functionality in a convenient and efficient manner. It's designed to be easy to integrate into your projects without the need for any external dependencies or incurring any runtime costs.

Please note that Polymorph-lib is not a polymorphic code engine that changes its code signature each time it runs. Instead, it draws inspiration from the concept of polymorphic code. You can simulate a polymorphic code engine by recompiling your program with Polymorph-lib each time you wish to run it.

# Use Cases

Polymorph-lib has several practical use cases:

    Binary Fingerprinting: Distribute functionally equivalent, yet different binaries to multiple users. This allows you to trace leaks back to specific recipients if your program gets leaked.

    Signature Evasion: Evade signature detection mechanisms by incorporating compile-time randomization into your code, making it difficult to detect signatures between different compiles.

    Non-Deterministic Algorithms: Efficient algorithms that rely on random numbers can be used at compile-time, thanks to the library's compile-time random number generators.

    Experimentation: Ensure that different code permutations are equivalent through random sampling. Compile your program multiple times with randomization to test their functionality.

# Usage

To integrate Polymorph-lib into your project, follow these simple steps:

    1. Place the include/polymorph-lib.h header file somewhere in your project directory.

    2. Include the library in your project using #include "polymorph-lib.h" or an equivalent include statement.

    3. Utilize the provided randomized functions. Some key functions include:

        poly_random(n): Obtain a random number between 0 (inclusive) and n (exclusive).

        poly_junk(): Generate junk code that doesn't perform any meaningful operations.

        poly_random_order(f1, f2): Execute functions f1 and f2 in a random order.

        poly_random_chance(c, f): Implement a random chance to call function f. Approximately every c distinct calls will trigger f once.

        poly_int(), poly_uint(), poly_ll(), poly_ull(), poly_float(), poly_double(): Generate random values of the specified data type (floating-point types range from 0.0 to 1.0).

        poly_normal(sigma, mu): Generate random floating-point values following a normal distribution with given sigma and mu values.

    4. Compile your code with some level of optimization to ensure that redundant branches are removed.

If you wish to set a specific seed manually or generate a seed using an external program, you can use the __POLY_RANDOM_SEED__ macro, like this: -D __POLY_RANDOM_SEED__=1234567890ull. This step is optional, as a seed will be automatically generated based on the current time if left unspecified.

# Details

Before delving into the random number generator's details, it's essential to understand the source of entropy used. Polymorph-lib leverages the __DATE__ and __TIME__ macros provided by GCC, which change with each compilation (assuming compilations occur in different seconds). These macros are combined into an integer, serving as the initial seed.

The library employs a counter-based pseudo-random number generator (CBPRNG) because using the PRNG's output as state for subsequent calculations isn't straightforward in compile-time scenarios. The __COUNTER__ macro, which increments automatically with each reference, serves as an ideal state for this purpose. Widynski's Squares CBPRNG, as described in this paper, is used for the purpose, and it can be evaluated at compile-time due to its constexpr nature.

To transform these compile-time random variables into different code, the library creates various branches of code using if or case statements, and then relies on compiler optimizations to eliminate unused branches.

It's worth noting that using functions in this manner would evaluate branch elimination only once, resulting in the same code output for all calls to poly_junk(). To overcome this limitation, the library employs #define macros, ensuring that the preprocessor replaces poly_junk() with corresponding code, enabling the compiler to evaluate each branch separately and produce different code outputs each time.
