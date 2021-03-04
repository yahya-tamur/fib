#include <inttypes.h>
#include <stdio.h>

// notice it's unsigned
uint64_t fib(uint64_t k) {
    uint64_t m0 = 0;
    uint64_t m1 = 1;
    uint64_t m2 = 1;
    uint64_t m3 = 1;

    uint64_t i0 = 0;
    uint64_t i1 = 1;

    // does declaring these here and not when they're needed help?
    uint64_t r0 = 0;
    uint64_t m0_m3 = 0;
    uint64_t m1m2 = 0;
    while (k != 0) {
        if (k & 1) {
            r0 = m0 * i0 + m1 * i1;
            i1 = m2 * i0 + m3 * i1;
            i0 = r0;
        }
        m0_m3 = m0 + m3;
        m1m2 = m1 * m2;

        m0 = m0 * m0 + m1m2;
        m1 *= m0_m3;
        m2 *= m0_m3;
        m3 = m3 * m3 + m1m2;
        k >>= 1;
    }
    return i0;
};
