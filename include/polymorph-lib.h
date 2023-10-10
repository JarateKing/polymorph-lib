#pragma once
#include <cmath>
#include <limits>
#include <ctime>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct PolyRandom {
private:
    static constexpr unsigned long long Square(unsigned long long x) {
        return x * x;
    }

    static constexpr unsigned long long Sum(unsigned long long x) {
        return Square(x) + x;
    }

    static constexpr unsigned long long Shift(unsigned long long x) {
        return (x >> 32) | (x << 32);
    }

public:
    // Generate a pseudo-random unsigned integer using Widynski Squares algorithm
    static constexpr unsigned int WidynskiSquares(unsigned long long count, unsigned long long seed) {
        unsigned long long cs = (count + 1) * seed;
        return static_cast<unsigned int>((Square(Shift(Square(Shift(Sum(cs))) + cs + seed)) + cs) >> 32);
    }

    // Generate a random number following a normal distribution using Box-Muller transform
    static constexpr double BoxMuller(double a, double b, double sigma, double mu) {
        const double epsilon = std::numeric_limits<double>::min();
        return sqrt(-2.0 * log(a + epsilon)) * cos(2.0 * M_PI * b) * sigma + mu;
    }

    // Generate a random seed based on the current time
    static constexpr unsigned long long Seed() {
        time_t rawtime;
        struct tm* timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        return static_cast<unsigned long long>(timeinfo->tm_sec) +
            static_cast<unsigned long long>(timeinfo->tm_min) * 60 +
            static_cast<unsigned long long>(timeinfo->tm_hour) * 3600 +
            static_cast<unsigned long long>(timeinfo->tm_mday) * 86400 +
            static_cast<unsigned long long>(timeinfo->tm_mon + 1) * 2678400 +
            static_cast<unsigned long long>(timeinfo->tm_year + 1900) * 31536000;
    }
};

// Macros for generating random values with different types
#define poly_uint() (PolyRandom::WidynskiSquares(__COUNTER__, PolyRandom::Seed()))
#define poly_int() static_cast<int>(poly_uint())
#define poly_ull() (static_cast<unsigned long long>(poly_int()) << 32 | poly_int())
#define poly_ll() static_cast<long long>(poly_ull())
#define poly_float() (static_cast<float>(poly_uint()) / static_cast<float>(UINT_MAX))
#define poly_double() (static_cast<double>(poly_ull()) / static_cast<double>(ULLONG_MAX))
#define poly_random(max) (poly_uint() % max)

// Macro for generating random junk code for obfuscation
#define poly_junk() { \
    int chance = poly_random(21); \
    if (chance == 0) { volatile int value = poly_random(10000); } \
    if (chance == 1) { volatile float value = poly_random(1000); } \
    if (chance == 2) { volatile double value = poly_random(1000); } \
    if (chance == 3) { volatile char value = poly_random(100000); } \
    if (chance == 4) { volatile int v[4] = {poly_random(1000), poly_random(1000), poly_random(1000), poly_random(1000)}; } \
    if (chance == 5) { volatile int v[2] = {poly_random(10000), poly_random(10000)}; volatile int vo = v[1] + v[2]; } \
    if (chance == 6) { volatile int v[2] = {poly_random(10000), poly_random(10000)}; volatile int vo = v[1] * v[2]; } \
    if (chance == 7) { volatile int v[2] = {poly_random(10000), poly_random(10000)}; volatile int vo = v[1] | v[2]; } \
    if (chance == 8) { volatile int v[2] = {poly_random(10000), poly_random(10000)}; volatile int vo = v[1] ^ v[2]; } \
    if (chance == 9) { volatile int v[2] = {poly_random(10000), poly_random(10000)}; volatile int vo = v[1] & v[2]; } \
    if (chance == 10) { volatile int v[2] = {poly_random(10000), poly_random(10000)}; volatile int vo = v[1] - v[2]; } \
    if (chance == 11) { volatile int v[2] = {poly_random(10000), poly_random(10000)}; volatile int vo = v[1] / (v[2] + 1); } \
    if (chance == 12) { volatile int v[2] = {poly_random(10000), poly_random(10000)}; volatile int vo = v[2] % (v[1] + 1); } \
    if (chance == 13) { volatile int v1 = poly_random(10000), v2 = v1 + poly_random(10000); } \
    if (chance == 14) { volatile int v1 = poly_random(10000), v2 = v1 * poly_random(10000); } \
    if (chance == 15) { volatile int v1 = poly_random(10000), v2 = v1 | poly_random(10000); } \
    if (chance == 16) { volatile int v1 = poly_random(10000), v2 = v1 ^ poly_random(10000); } \
    if (chance == 17) { volatile int v1 = poly_random(10000), v2 = v1 & poly_random(10000); } \
    if (chance == 18) { volatile int v1 = poly_random(10000), v2 = v1 - poly_random(10000); } \
    if (chance == 19) { volatile int v1 = poly_random(10000), v2 = v1 / (poly_random(10000) + 1); } \
    if (chance == 20) { volatile int v1 = poly_random(10000), v2 = v1 % (poly_random(10000) + 1); } \
}

// Macros for randomizing the order of execution of two functions
#define poly_random_order(f1, f2) { \
    int chance = poly_random(2); \
    if (chance == 0) { f1; f2; } \
    else { f2; f1; } \
}

// Macro for executing a function with a certain random chance
#define poly_random_chance(c, f) { \
    int chance = poly_random(c); \
    if (chance == 0) { f; } \
}

// Macro for generating random values following a normal distribution
#define poly_normal(sigma, mu) (PolyRandom::BoxMuller(poly_double(), poly_double(), sigma, mu))
