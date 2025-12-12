/*Adapoted from PATC 2024 @BSC */
/* test.c - Compiler Optimization Benchmark */
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 8000
typedef double matrix[SIZE][SIZE];

/* Declared globally to avoid stack overflow (these require ~1GB RAM total) */
matrix m1, m2; 
struct timeval start_time, end_time;

static void foo(void) {
    int i, j;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            m1[i][j] = 8.0 / m2[i][j];
        }
    }
}

void check_matrix() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            /* 8.0 / 2.5 should equal 3.2 exactly in IEEE 754 double precision */
            if (m1[i][j] != 3.2) {
                printf("Check failed at [%d][%d]\n", i, j);
                exit(1);
            }
        }
    }
    printf("Check passed.\n");
}

void print_times() {
    long total_usecs;
    float total_time;
    
    total_usecs = (end_time.tv_sec - start_time.tv_sec) * 1000000 +
                  (end_time.tv_usec - start_time.tv_usec);
    
    printf("Time: %.2f mSec \n", ((float)total_usecs) / 1000.0);
}

int main() {
    int i, j;

    printf("Initializing matrices...\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            m2[i][j] = 2.5;
        }
    }

    printf("Starting benchmark (10 iterations)...\n");
    gettimeofday(&start_time, NULL);

    for (i = 0; i < 10; ++i) {
        foo();
    }

    gettimeofday(&end_time, NULL);

    print_times();
    check_matrix();
    
    return 0;
}
