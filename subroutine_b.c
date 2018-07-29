#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *bytes_L1;

void random_assign_b(char *bytes, int len){

    for (int i=0; i<len; i++){
        *(bytes + i) = (wint_t)((clock()+i));        //assigning random values based on sys clock
    }
}

void subroutine_b(){
    //Subroutine B
    //increment each b1 th byte of a memory buffer containing 2* L1 capacity

    bytes_L1 = malloc(2*32*1024);

    if (!bytes_L1) {
        fprintf(stderr, "Memory allocation failed\n");
        abort();
    }

    random_assign_b(bytes_L1, 65536);

    //--------------------------------------------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------------------------------------------------

    double time_used_b = 0;
    clock_t start_b = clock();

    for (int j=0; j<850000; j++){                         //Loop for increasing number of experiments. j was adjusted so that the execution time > 1s
        for (int i=64; i<65536; i=i+64){
            *(bytes_L1 + i) = *(bytes_L1 + i) + 1;
        }
    }

    clock_t end_b = clock();
    time_used_b = ((double)(end_b - start_b));
    time_used_b = time_used_b/CLOCKS_PER_SEC;
    printf("Time taken by Subroutine B: %lf\n", time_used_b);
    printf("Bandwidth of Subroutine B: %lf Mbps\n", 341000*64/(time_used_b*1024));
    int sum = 0;
    for (int i=0; i<65536; i++){
        sum = sum + *(bytes_L1 + i);
    }
    printf("Calculated sum: %d\n", sum);

    free(bytes_L1);
}
