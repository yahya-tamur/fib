Started off as me trying to write a log(n) fibonacci function without implementing
matrix and vector data types. I wouldn't say I was successful there. The code
still basically does matrix multiplication and it's pretty much unreadable.

That being said, I wrote a file for handling big numbers and this can calculate
the fibonacci number for very large values pretty fast. On my computer, finding
the millionth fibonacci number takes about 8 seconds.

Note: In math, there is a formula for the n'th fibonacci number. I've seen that
implementation referred to as O(1). But, that relies on floating point numbers and
does things like floating point exponentiation, so I'm not sure how fast or
accurate or O(1) it is. This program gives the exact answer if it doesn't
overflow -- you can adjust the size of the answer if it seems to have.

Also note that you can find the first n fibonacci numbers much faster and easier.
The novelty of this program is that it doesn't calculate all previous fibonacci
numbers to find the n'th one while just using integer addition and multiplication.

-----------------
Notes / Pseudocode

With matrices, here's the problem:
given a matrix M, integer k, and a vector I, find M^k I

and here's the log(k) solution:
initialize k, M, i
while k != 0:
    if k&1
        i = Mi
    m*= m
    k >>= 1

Here's that algorithm in this use case:
M = \[1 0\] variable names: [m0 m1]
    \[1 1\]                 [m2 m3]

i = \[0\] variable names: [i0]
    \[1\]                 [i1]

k = input

The following code isn't very scientific or anything. I just looked at the problem
and tried to write it in a way which avoids doing the same calculations multiple
times and accounts for the fact that I have only one copy of each number. I
wouldn't be surprised if it was or wasn't optimal.


while k != 0
    if k&1
        r0 = m0*i0 + m1*i1
        i1 = m2*i0 + m3*i1
        i0 = r0

    m0\_m3 = m0 + m3
    m1m2 = m1*m2

    m0 = m0*m0 + m1m2
    m1 *= m0_m3
    m2 *= m0_m3
    m3 = m3*m3 + m1m2
    k >>= 1


I wrote the big\_number file following along with The Art of Computer Programming
Volume 2, Chapter 4.3 Multiple Precision Arithmetic.

It was way simpler than I thought it would be, but I guess you do have to do all n
pairwise additions to add and all n^2 operations to multiply.

The long\_fib is a little different than the pseudocode here to account for the
way the functions in big\_number work. It looks a lot like assembly code, which I
thought was cool.

Running
-------
fib(uint64\_t k) finds the k'th fibonaccci number, long\_fib(uint64\_k, uint32\_n)
finds the k'th fibonacci number using 8\*n bit integers, and returns a BigNumber\*.
You can print that using print\_num and free it using free\_num\_ptr.

Apparently the program spends almost all of its time doing multiply\_add.

gprof:
`export LD_PROFILE=long_fib.o
`make clean`
`make`
`gprof ./a.out ./gmon.out`

I did not include the .clang-format file I used since it's the same exact one
provided in one of my classes. Don't run `make clean`.

out.txt has the millionth fibonacci number in hex.
