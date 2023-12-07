#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int arr[], int n){
    int i, j, temp;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    bubbleSort(arr, n);
    displayArray(arr, n);
    return 0;
}