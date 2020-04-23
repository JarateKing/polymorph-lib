// ================
// COMPILE-TIME RNG
// ================

struct poly {
private:
	// common types
	typedef unsigned long long ull;
	typedef unsigned int ui;

    // arithmetic simplification functions
    static constexpr ull sq(ull x) { return x * x; }
    static constexpr ull sm(ull x) { return sq(x) + x; }
    static constexpr ull sh(ull x) { return (x>>32) | (x<<32); }
    
public:
    // normal prng's are hard to use here, since we can't easily modify our state
	// we need to use a counter-based rng, to use __COUNTER__ as our state instead
	// https://en.wikipedia.org/wiki/Counter-based_random_number_generator_(CBRNG)
	// we use Widynski's Squares method to achieve this: https://arxiv.org/abs/2004.06278
    static constexpr ui Widynski_Squares(ull count, ull seed) {
        unsigned long long cs = (count + 1) * seed;
        return (sq(sh(sq(sh(sm(cs))) + cs + seed)) + cs) >> 32;
    }
    
    // we define our seed based off of the __DATE__ and __TIME__ macros
	// this allows us to have different compile-time seed values
    static constexpr ull Seed = (__DATE__[10] - '0') +
                                (__DATE__[9] - '0') * 10 +
                                (__DATE__[5] - '0') * 100 +
                                (__TIME__[0] - '0') * 1000 +
                                (__TIME__[1] - '0') * 10000 +
                                (__TIME__[3] - '0') * 100000 +
                                (__TIME__[4] - '0') * 1000000 +
                                (__TIME__[6] - '0') * 10000000 +
                                (__TIME__[7] - '0') * 100000000;
};

// we also define a convenient interface to getting the next random
#define RANDO(max) (poly::Widynski_Squares(__COUNTER__, poly::Seed) % max)

// =====================
// POLYMORPHIC FUNCTIONS
// =====================

