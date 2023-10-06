#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high){
    int left = low, right = mid + 1;
    int temp[high - low + 1];
    int i = 0;

    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
            temp[i++] = arr[left++];
        }else{
            temp[i++] = arr[right++];
        }
    }
    while(left <= mid){
        temp[i++] = arr[left++];
    }
    while(right <= high){
        temp[i++] = arr[right++];
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

void mergeSortSerial(int arr[], int low, int high){
    if(low >= high) return;
    int mid = (high + low)/2;

    #pragma omp parallel sections
    {   
        #pragma omp section
        mergeSortSerial(arr, low, mid);
        #pragma omp section
        mergeSortSerial(arr, mid + 1, high);
    }
    merge(arr, low, mid, high);
    
}

void mergeSortParallel(int arr[], int low, int high){
    if(low >= high) return;
    int mid = (high + low)/2;
    mergeSortSerial(arr, low, mid);
    mergeSortSerial(arr, mid + 1, high);

    merge(arr, low, mid, high);
    
}

void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n = 0;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++){
        arr[i] = rand()%100;
    }

    double start = omp_get_wtime();
    mergeSortSerial(arr, 0, n - 1);
    display(arr, n);
    double end = omp_get_wtime();
    printf("Time taken Serial = %f \n", (end - start));

    start = omp_get_wtime();
    mergeSortParallel(arr, 0, n - 1);
    end = omp_get_wtime();
    printf("Time taken Parallel = %f \n", (end - start));
}