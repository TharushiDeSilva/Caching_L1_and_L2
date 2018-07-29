#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *bytes_L2;

void random_assign_c(char *bytes, int len){

    for (int i=0; i<len; i++){
        *(bytes + i) = (wint_t)((clock()+i));        //assigning random values based on sys clock
    }
}

void subroutine_c(){
    //Subroutine C
    //increment each b2 th byte of a memory buffer containing 2* L2 cache capacity bytes

    bytes_L2 = malloc(2*256*1024);

    if (!bytes_L2) {
        fprintf(stderr, "Memory allocation failed\n");
        abort();
    }

    random_assign_c(bytes_L2, 524288);

    //-------------------------------------------------------------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------------------------------------------------------

    double time_used_c = 0;
    clock_t start_c = clock();

    for (int j=0; j<6400; j++){                          //Loop for increasing number of experiments. j was adjusted so that the execution time > 1s
        for (int i=64; i<524288; i=i+64){                 //524288 = 512 kB (2*256)
            *(bytes_L2 + i) = *(bytes_L2 + i) + 1;
        }
    }

    clock_t end_c = clock();
    time_used_c = ((double)(end_c - start_c));
    time_used_c = time_used_c/CLOCKS_PER_SEC;
    printf("Time taken by Subroutine C: %lf\n", time_used_c);
    printf("Bandwidth of Subroutine C: %lf Mbps\n", 42400*512/(time_used_c*1024));

    int sum = 0;
    for (int i=0; i<524288; i++){
        sum = sum + *(bytes_L2 + i);
    }
    printf("Calculated sum: %d\n", sum);

    free(bytes_L2);
}