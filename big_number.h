#ifndef __BIG_NUMBER_H__
#define __BIG_NUMBER_H__

#include <inttypes.h>

// yeah it's not opaque
typedef struct BigNumber {
    uint32_t num_digits;
    uint32_t *data; // LSB is data[0]
} BigNumber;

BigNumber *allocate_num(uint32_t k, uint32_t n);

void free_num_ptr(BigNumber *n);

void print_num(BigNumber *n);

void set_to_zero(BigNumber *n);

//c = a+b
void plus(BigNumber *a, BigNumber *b, BigNumber *c);

//c += a*b
void multiply_add(BigNumber *a, BigNumber *b, BigNumber *c);

//hex, all significant digits including leading zeroes
void print_num(BigNumber *n);

#endif
