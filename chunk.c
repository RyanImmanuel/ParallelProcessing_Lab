#include <omp.h>
#include <stdio.h>

int main(){
    int n = 10;
    omp_set_schedule(omp_sched_static, 2);

    double start = omp_get_wtime();

    #pragma omp parallel for schedule(runtime)
    for(int i = 0; i < n; i++){
        int thread_num = omp_get_thread_num();

        printf("Thread %d executing iteration %d\n", thread_num, i);
    }

    double end = omp_get_wtime();

    printf("Time taken for parallel processing is %f", (end - start));

    return 0;
}