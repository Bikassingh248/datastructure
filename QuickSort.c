#include<stdio.h>
#include<stdlib.h>
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    int temp;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            // swap
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // swap
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);        
    }
}
void displayArray(int arr[], int n){
    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n < 0){
        printf("Please enter a positive number");
        return 1;
    }
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    displayArray(arr, n);
    return 0;
}5