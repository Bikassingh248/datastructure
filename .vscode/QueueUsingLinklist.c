#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Queue{
    struct Node* front;
    struct Node* rear;
};
struct Node* createNode(int data){
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Queue* createQueue(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
void enqueue(struct Queue* queue, int data){
    struct Node* newNode = createNode(data);
    if(queue->rear == NULL){
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}
int dequeue(struct Queue* queue){
    if(queue->front == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return data;
}
void display(struct Queue* queue){
    if(queue->front == NULL){
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp= queue->front;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    struct Queue* queue = createQueue();
    int choice, data;
    do{
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if(data != -1){
                    printf("Dequeued %d\n", data);
                }
                break;
            case 3:
                printf("Queue elements:\n");
                display(queue);
                break;
            case 4:
                printf("Exiting from app.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }while(choice != 4);
    return 0;
}
    
