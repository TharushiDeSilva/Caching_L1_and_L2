

How to compile: gcc -o Lab4 main.c subroutine_a.c subroutine_b.c subroutine_c.c Lab4.h -O4

How to run:     ./Lab4        [ or simply Lab4(on windows)]



System dependant variables:
        if using Windows,  change the "u_int8_t" variable into "wint_t"
        * it can be found in    subroutine_a: line 11,
                                subroutine_b: line 11,
                                subroutine_c: line 11.

the loop counts in the 3 subroutines are chosen to finish executing within 1s, in the following computer
        Intel core i7 6600U, Skylake
        2.50GHz
        L1 cache D- 32kB x 2    - 8 way
        L2 cache   - 256 kB x 2 - 4 way
