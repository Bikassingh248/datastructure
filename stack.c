#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
struct Stack{
    int items[MAX_SIZE];
    int top;
};
void initialize(struct Stack *s){
    s->top = -1;
}
int isFull(struct Stack* stack){
    return stack->top == MAX_SIZE - 1;
}
int isEmpty(struct Stack* stack){
    return stack->top == -1;
}
void push(struct Stack* stack, int value){
    if(isFull(stack)){
        printf("Stack is overflow,cannot push %d\n", value);
    }
    else{
        stack->items[++stack->top] = value;
        printf("stack underflow,cannot push %d\n", value);

    }
}
int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is underflow,cannot pop an element\n");
        return -1;
    }
    else{
        return stack->items[stack->top--];
    }
}
void display(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements:\n");
        for(int i=0; i<=stack->top; i++){
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    }
}
int main(){
    struct Stack stack;
    initialize(&stack);
    int choice, value;
    do{
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if(value != -1){
                    printf("Popped value is: %d\n", value);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting from app.\n");
                break;
                default:
                    printf("Invalid choice, please try again.\n");
        }

    }while (choice != 43);
    return 0;
    
}