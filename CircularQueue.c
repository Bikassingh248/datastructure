#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct CircularQueue
{
    int array[MAX];
    int front;
    int rear;
};
void initializeQueue(struct CircularQueue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}
int isEmpty(struct CircularQueue *queue)
{
    return queue->front == -1;
}
int isFull(struct CircularQueue *queue)
{
    return (queue->rear + 1) % MAX == queue->front;
}
void enqueue(struct CircularQueue *queue, int data)
{
    if (isFull(queue))
    {
        printf("Queue is full");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->array[queue->rear] = data;
    printf("%d enqueued to queue\n", data);
}
int dequeue(struct CircularQueue *queue)
{

    int data = -1;
    if (isEmpty(queue))
    {
        printf("Queue is empty");
        return data;
    }
    data = queue->array[queue->front];
    if (queue->front == queue->rear)
    {
        initializeQueue(queue);
    }
    else
    {
        queue->front = (queue->front + 1) % MAX;
    }
    printf("%d dequeued from queue\n", data);
    return data;
}
void displayQueue(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty");
        return;
    }
    printf("circular queue elements are:\n");
    int i = queue->front;
    do
    {
        printf("%d ", queue->array[i]);
        i = (i + 1) % MAX;
    } while (i != (queue->rear + 1) % MAX);
    printf("\n");
}
int main()
{
    struct CircularQueue queue;
    initializeQueue(&queue);
    int choice, data;
    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(&queue, data);
            break;
        case 2:
            dequeue(&queue);
            break;
        case 3:
            displayQueue(&queue);
            break;
        case 4:
            printf("Exiting from app.\n");
            exit(0);
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
    return 0;
}