#include <stdio.h>
#include <stdlib.h> //for rand
#include <omp.h>

void addition(int n, int vectorAns[], int vectorA[], int vectorB[]){
        #pragma omp parallel for
        for(int i = 0; i < n; i++){
            vectorAns[i] = vectorA[i] + vectorB[i];
            printf("%d ", vectorAns[i]);
        }
}

int main(){
    int n = 100;
    int vectorAns[n], vectorA[n], vectorB[n];

    for(int i = 0; i < n; i++){
        vectorA[i] = rand()%100;
        vectorB[i] = rand()%10;
    }

    double start = omp_get_wtime();
    addition(n, vectorAns, vectorA, vectorB);
    double end = omp_get_wtime();

    printf("\n %f seconds", (end - start));
}