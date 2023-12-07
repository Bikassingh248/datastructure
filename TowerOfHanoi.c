#include<stdlib.h>
void moveDisk(int disk,char source,char destination){
    printf("move disk %d from rod %c to rod %c\n",disk,source,destination);
}
void towerOfHanoi(int numDisks,char source,char auxiliary,char destination){
    if(numDisks == 1){
        moveDisk(1,source,destination);
        return;
    }
    towerOfHanoi(numDisks - 1,source,destination,auxiliary);
    moveDisk(numDisks,source,destination);
    towerOfHanoi(numDisks - 1,auxiliary,source,destination);
}
void displayTowerOfHanoi(int numDisks){
    towerOfHanoi(numDisks,'A','B','C');
}
int main(){
    int numDisks;
    printf("Enter number of disks: ");
    scanf("%d",&numDisks);
    if(numDisks < 0){
        printf("Please enter a positive number");
        return 1;
    }
    displayTowerOfHanoi(numDisks);
    return 0;
}