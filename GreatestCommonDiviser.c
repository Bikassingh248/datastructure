#include<stdio.h>
gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a % b);
    }
}
void displayGCD(int a, int b){
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
}
int main(){
    int a, b;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    displayGCD(a, b);
    return 0;
}