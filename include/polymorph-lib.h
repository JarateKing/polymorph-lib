// ================
// COMPILE-TIME RNG
// ================

// we define our seed based off of the __TIME__ string
// this allows us to have different compile-time seed values
constexpr unsigned int Seed = (__TIME__[0] - '0') * 1 +
                              (__TIME__[1] - '0') * 10 +
                              (__TIME__[3] - '0') * 100 +
                              (__TIME__[4] - '0') * 1000 +
                              (__TIME__[6] - '0') * 10000 +
                              (__TIME__[7] - '0') * 100000;

// we need to use a counter-based rng, to use __COUNTER__ as our state
// https://en.wikipedia.org/wiki/Counter-based_random_number_generator_(CBRNG)
// we use Widynski's Squares method to achieve this: https://arxiv.org/abs/2004.06278
constexpr unsigned int Widynski_Squares(unsigned int count, unsigned int seed) {
    unsigned long long a = count * seed;
    unsigned long long b = a + seed;
    unsigned long long c = a * a + a;
    unsigned long long d = (c>>32) | (c<<32);
    unsigned long long e = d * d + b;
    unsigned long long f = (e>>32) | (e<<32);
    return (f*f + a) >> 32;
}

// we also define a convenient interface to getting the next random
#define RANDO(max) (Widynski_Squares(__COUNTER__, Seed) % max)

// =====================
// POLYMORPHIC FUNCTIONS
// =====================
