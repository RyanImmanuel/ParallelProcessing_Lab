#include <stdio.h>
#include <omp.h>

int main(){
    int n = 0;
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    int fib[n];

    fib[0] = 0;
    fib[1] = 1;

    #pragma omp parallel for schedule(dynamic)
    for(int i = 2; i < n; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("Fibonacci Series : \n");
    for(int i = 0; i < n; i++){
        printf("%d ", fib[i]);
    }

    return 0;
}