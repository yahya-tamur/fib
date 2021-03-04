#ifndef __LONG_FIB_H__
#define __LONG_FIB_H__

#include "big_number.h"

#include <stdint.h>

// second input is the number of uint32_t's used to represent a number
BigNumber *long_fib(uint64_t k, uint32_t n);

#endif
