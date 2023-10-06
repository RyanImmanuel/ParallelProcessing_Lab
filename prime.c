#include <stdio.h>
#include <stdlib.h> 
#include <omp.h>

int isPrime(int n){
    if(n <= 1) return 0;
    for(int i = 2; i < n/2; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int n = 100000;
    int count = 0;
    
    double start = omp_get_wtime();
    //series execution
    for(int i = 0; i < n; i++){
        if(isPrime(i)){
            count++;
        }
    }
    printf("\n %d \n", count);
    double end = omp_get_wtime();
    printf("Serial version : %f", (end - start));

    start = omp_get_wtime();
    //parallel execution
    count = 0;
    #pragma omp parallel for
    for(int i = 0; i < n; i++){
        if(isPrime(i)){
            count++;
        }
    }
    printf("\n %d \n", count);
    end = omp_get_wtime();
    printf("Parallel version : %f", (end - start));

    return 0;
}
