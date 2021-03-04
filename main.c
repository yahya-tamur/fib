#include "big_number.h"
#include "long_fib.h"

#include <stdio.h>
#include <time.h>

//prints time to stderr, output to stdout
int main() {
    clock_t start, end;
    start = clock();
    //the second input is the number of words the return value will occupy.
    //Smaller means the program runs faster, but the answer may overflow.
    BigNumber *num = long_fib(1000000, 50000);
    end = clock();
    print_num(num);
    fprintf(stderr, "Time used: %lf\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    free_num_ptr(num);
    return 0;
}
