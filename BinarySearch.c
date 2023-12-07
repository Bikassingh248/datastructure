#include<stdio.h>
void displayArray(int arr[], int n){
    printf("array elements: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");                   
}
int binarySearch(int arr[], int n, int key){
    int low = 0, high = n - 1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] < key){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    int n, key;
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
    displayArray(arr, n);
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, n, key);
    if(result == -1){
        printf("Key not found\n");
    }else{
        printf("Key found at index %d\n", result);
    }
    return 0;
}