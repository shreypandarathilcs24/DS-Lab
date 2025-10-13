#include <stdio.h>
#define N 2

int front = -1;
int rear = -1;
int queue[N];

void enque()
{
    int x;
    printf("Enter the element to enque: ");
    scanf("%d", &x);

    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    }
    else if (rear == N - 1) {
        printf("Queue Overflow\n");
    }
    else {
        queue[++rear] = x;
    }
}

void deque()
{
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else if (front == rear) {
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Dequeued element: %d\n", queue[front++]);
    }
}

void peek()
{
    if (front == -1 && rear == -1) {
        printf("Queue Empty\n");
    }
    else {
        printf("Front element: %d\n", queue[front]);
    }
}

void display()
{
    if (front == -1 && rear == -1) {
        printf("Queue empty\n");
    }
    else {
        printf("Queue elements:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

void main()
{
    int choice = 0;
    while (choice != 5)
    {
        printf("\nEnter 1 for enque, 2 for deque, 3 for peek, 4 for display, 5 to exit: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: enque(); break;
            case 2: deque(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n");
        }
    }
}
