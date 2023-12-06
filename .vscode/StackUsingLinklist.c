#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Stack{
    struct Node* top;
};
struct Node* createNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct  Stack* initializestack(){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}
void push(struct Stack* stack, int data){
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d\n", data);
}
void pop(struct Stack* stack){
    if(stack->top == NULL){
        printf("Stack is empty\n");
    exit(EXIT_FAILURE);
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
    }
    void display(struct Stack* stack){
        if(stack->top == NULL){
            printf("Stack is empty\n");
            return;
        }
        struct Node* current = stack->top;
        printf("Stack elements:\n");
        while(current!= NULL){
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
    int main(){
        struct Stack* stack = initializestack();
        int choice, data;
        do{
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Display\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    printf("Enter data to push: ");
                    scanf("%d", &data);
                    push(stack, data);
                    break;
                case 2:
                    if (stack->top == NULL){
                        printf("popped element is %d\n", pop(stack));
                    }
                    else{
                        printf("Stack is empty\n");
                    }
                    break;
                    
                    
                case 3:
                    display(stack);
                    break;
                case 4:
                    printf("exiting from program\n");
                    break;
                default:
                    printf("Invalid choice, please try again\n");
            }
        }while(choice!=4);
        free(stack);
        return 0;
    }