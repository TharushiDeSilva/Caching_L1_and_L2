#include "Lab4.h"

//L1 cache size = 32K
//L2 cache size = 256K
//L3 cache size = 3072K
//b1, b2 = 64


int main() {

    //printf("before: %d\n", *(bytes_L1+128));
    subroutine_a();
    //printf("after: %d\n", *(bytes_L1+128));

    //printf("before: %d\n", *(bytes_L1+128));
    subroutine_b();
    //printf("after: %d\n", *(bytes_L1+128));

    //printf("before: %d\n", *(bytes_L2+128));
    subroutine_c();
    //printf("after: %d\n", *(bytes_L2+128));

    return(0);
}