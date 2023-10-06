#include <stdio.h>
#include <omp.h>

int main(){
    int n = 100;
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for(int i = 1; i <= n; i++){
        #pragma omp critical
        sum += i;
    }
    printf("%d", sum);

    return 0;
}