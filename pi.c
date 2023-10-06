#include <stdio.h>
#include <omp.h>
#define num 10000000

int main(){
    double pi = 0;

    //series
    double start = omp_get_wtime();
    for(int k = 0; k  < num;  k++){
        pi += (4 * (k%2 == 0 ? 1.0 : -1.0 ))/(2*k + 1);
    }
    printf("%6.12f\n", pi);
    double end = omp_get_wtime();
    printf("Time taken for series : %f \n", (end - start));

    // parallel
    pi = 0;
    start = omp_get_wtime();
    #pragma omp parallel for reduction(+:pi)
    for(int k = 0; k < num; k++){
        pi += (4 * (k%2 == 0 ? 1.0 : -1.0))/(2*k + 1);
    }
    printf("%6.12f\n", pi);
    end = omp_get_wtime();
    printf("Time taken for parallel : %f \n", (end - start));

    return 0;
}