#include<stdio.h>
#include<stdlib.h>
void insertionSort(int arr[], int n){
    int i, j, key;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    insertionSort(arr, n);
    displayArray(arr, n);
    return 0;
}
