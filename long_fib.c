#include "long_fib.h"

#include "big_number.h"

#include <inttypes.h>
#include <stdio.h>

// sorry
void swap(BigNumber **a, BigNumber **b) {
    *a = (BigNumber *) ((uintptr_t) *a ^ (uintptr_t) *b);
    *b = (BigNumber *) ((uintptr_t) *a ^ (uintptr_t) *b);
    *a = (BigNumber *) ((uintptr_t) *a ^ (uintptr_t) *b);
    return;
}

// second input is the number of uint32_t's used to represent a number
BigNumber *long_fib(uint64_t k, uint32_t n) {
    BigNumber *m0 = allocate_num(0, n);
    BigNumber *m1 = allocate_num(1, n);
    BigNumber *m2 = allocate_num(1, n);
    BigNumber *m3 = allocate_num(1, n);

    BigNumber *i0 = allocate_num(0, n);
    BigNumber *i1 = allocate_num(1, n);

    //temporary values
    BigNumber *r0 = allocate_num(0, n);
    BigNumber *r1 = allocate_num(0, n);

    BigNumber *m0_m3 = allocate_num(0, n);
    BigNumber *m1m2 = allocate_num(0, n);
    while (k != 0) {
        if (k & 1) {
            set_to_zero(r0);
            multiply_add(m0, i0, r0);
            multiply_add(m1, i1, r0);

            set_to_zero(r1);
            multiply_add(m2, i0, r1);
            multiply_add(m3, i1, r1);

            swap(&r0, &i0);
            swap(&r1, &i1);
        }

        plus(m0, m3, m0_m3);

        set_to_zero(m1m2);
        multiply_add(m1, m2, m1m2);

        set_to_zero(r0);
        multiply_add(m0, m0, r0);
        plus(r0, m1m2, m0);

        set_to_zero(r0);
        multiply_add(m1, m0_m3, r0);
        swap(&r0, &m1);

        set_to_zero(r0);
        multiply_add(m2, m0_m3, r0);
        swap(&r0, &m2);

        set_to_zero(r0);
        multiply_add(m3, m3, r0);
        plus(r0, m1m2, m3);

        k >>= 1;
    }
    free_num_ptr(m0);
    free_num_ptr(m1);
    free_num_ptr(m2);
    free_num_ptr(m3);
    free_num_ptr(i1);
    free_num_ptr(r0);
    free_num_ptr(r1);
    free_num_ptr(m0_m3);
    free_num_ptr(m1m2);
    return i0;
};
