#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
int isFull()
{
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}
int isEmpty()
{
    return front == -1;
}
void enqueue(int element)
{
    if (isFull())
    {
        printf("Queue is full! Cannot enqueue %d.\n", element);
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1 && front != 0) //rear is at end and front is not 0th element
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = element;
    printf("Enqueued %d to the queue.\n", element);
}
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    printf("Dequeued %d from the queue.\n", data);
    return data;
}
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
