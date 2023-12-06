#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
struct Queue{
    int items[MAX_SIZE];
    int front;
    int rear;
};
void initialize(struct Queue* queue){
    queue->front = -1;
    queue->rear = -1;
}
int isFull(struct Queue* queue){
    return (queue->rear == MAX_SIZE - 1 && queue->front == 0) || (queue->rear + 1 == queue->front);
}
int isEmpty(struct Queue* queue){
    return queue->front == -1;
}
void enqueue(struct Queue* queue, int value){
    if(isFull(queue)){
        printf("Queue is full, cannot enqueue %d\n", value);
    }
    else{
        if(queue->front == -1){
            queue->front = 0;
        }   
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
        printf("Inserted -> %d\n", value);
    }
}
int dequeue(struct Queue* queue){
    int value=-1;
    if(!isEmpty(queue)){
        value = queue->items[queue->front];
        if(queue->front == queue->rear){
            queue->front = -1;
            queue->rear = -1;
        }
        else{
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
    }
    else{
        printf("queue is empty, cannot dequeue an element\n");
    }
    return value;

}
void display(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
    }
    else{
        printf("queue elements:");
        int i=queue->front;
        do{
            printf("%d ", queue->items[i]);
            i = (i + 1) % MAX_SIZE;
        }
        while(i != (queue->rear + 1) % MAX_SIZE);
        printf("\n");
    }
        
}
int main(){
    struct Queue queue;
    initialize(&queue);
    int choice, value;
    do{
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                value = dequeue(&queue);
                if(value != -1){
                    printf("Dequeued value is: %d\n", value);
                }
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting from program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }while (choice != 4);
    return 0;
}