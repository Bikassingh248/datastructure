#include<stdio.h>
#include<stdlib.h>
int sumOfNaturalNumber(int n){
    if(n == 0){
        return 0;
    }else{
        return n + sumOfNaturalNumber(n - 1);
    }
}
void displaySum(int n){
    printf("Sum of first %d natural numbers is %d\n", n, sumOfNaturalNumber(n));
}
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    if(n < 0){
        printf("Please enter a positive number");
        return 1;
    }
    displaySum(n);
    return 0;
}