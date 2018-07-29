#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *bytes_L1;

void random_assign_a(char *bytes, int len){

    for (int i=0; i<len; i++){
        *(bytes + i) = (wint_t)((clock()+i));        //assigning random values based on sys clock
    }
}

void subroutine_a(){
     //Subroutine A
    //increment all bytes of a memory buffer containing 2*L1 capacity bytes


    bytes_L1 = malloc(2*32*1024);

    if (!bytes_L1) {
        fprintf(stderr, "Memory allocation failed\n");
        abort();
    }

    random_assign_a(bytes_L1, 65536);

    // -------------------------------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------------------------------
    double time_used_a = 0;
    clock_t start_a = clock();

    for (int j=0; j<22300; j++){                             //Loop for increasing number of experiments. j was adjusted so that the execution time > 1s
        for (int i=0; i<65536; i++){                            // 65536 = 64 kB (2*32)
            *(bytes_L1 + i) = *(bytes_L1 + i) + 1;
        }
    }

    clock_t end_a = clock();
    time_used_a = ((double)(end_a - start_a));
    time_used_a = time_used_a/CLOCKS_PER_SEC;
    printf("Time taken by Subroutine A: %lf\n", time_used_a);
    printf("Bandwidth of Subroutine A: %lf Mbps\n", 5500*64/(time_used_a*1024));

    int sum = 0;
    for (int i=0; i<65536; i++){
        sum = sum + *(bytes_L1 + i);
    }
    printf("Calculated sum: %d\n", sum);
    free(bytes_L1);
}





