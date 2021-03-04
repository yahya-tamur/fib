// I'm following along The Art of Computer Programming Volume 2, Chapter 4.3
// multiple precision arithmetic
// It was way simpler than I thought it would be, but I guess you do have to add
// do n operations in add and n^2 operations in multiply

// with base 2^32 non-negative integers with elementary operations (a+b) and
//(1LL * A * B)
// I don't know if that produces efficient code but ok I don't want to go too
// far with that
//
// this should really be written on asssembly I think

#include "big_number.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// makes a big number with initial value k, number of uint32_t's n
// the struct itself is small enough so I'm just passing it, once per program
BigNumber *allocate_num(uint32_t k, uint32_t n) {
    uint32_t *data = calloc(n, sizeof(uint32_t));
    data[0] = k;
    BigNumber *ans = malloc(sizeof(BigNumber));
    ans->num_digits = n;
    ans->data = data;
    return ans;
}

void free_num_ptr(BigNumber *n) {
    free(n->data);
    free(n);
    return;
}

void set_to_zero(BigNumber *n) {
    for (uint32_t i = 0; i < n->num_digits; ++i) {
        n->data[i] = 0;
    }
    return;
}

// doesn't print more than 8 leading zeroes
void print_num(BigNumber *n) {
    bool started = false;
    for (int i = n->num_digits - 1; i >= 0; --i) {
        started |= n->data[i];
        if (started) {
            printf("%08x", n->data[i]);
        }
    }
    printf("\n");
    return;
}

// c = a + b
void plus(BigNumber *a, BigNumber *b, BigNumber *c) {
    uint32_t j = 0;
    uint32_t k = 0;
    for (int j = 0; j < a->num_digits; ++j) {
        c->data[j] = a->data[j] + b->data[j] + k;
        // basically to check if a+b+c > N
        // 1. check if a+b > N  = if a > N - b
        // 2. if not, check if (a+b)+c > N = c > N - (a+b)
        k = a->data[j] > UINT32_MAX - k || b->data[j] > UINT32_MAX - a->data[j] - k;
    }
    return;
}

// c += a*b
// assumes num_digits of a, b, c are all same
// even though a*b can have twice as many significant digits as a and b
void multiply_add(BigNumber *a, BigNumber *b, BigNumber *c) {
    for (uint32_t i = 0; i < a->num_digits; ++i) {
        if (!a->data[i]) {
            continue;
        }
        uint32_t k = 0;
        for (uint32_t j = 0; i + j < a->num_digits; ++j) {
            uint64_t t = 1LL * a->data[i] * b->data[j] + c->data[i + j] + k;
            k = (uint32_t)(t >> 32);
            c->data[i + j] = (uint32_t) t;
        }
    }
    return;
}
