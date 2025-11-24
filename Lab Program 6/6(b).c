#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//STACK FNS

struct Node* push(struct Node* top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = top;
    return newNode;
}

struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return NULL;
    }
    struct Node* temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
    return top;
}

void displayStack(struct Node* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

//QUEUE FNS

struct Node* enqueue(struct Node* rear, int data, struct Node** front) {
    struct Node* newNode = createNode(data);

    if (*front == NULL) {
        *front = newNode;
        return newNode;
    }

    rear->next = newNode;
    return newNode;
}

struct Node* dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue Underflow!\n");
        return NULL;
    }

    struct Node* temp = *front;
    printf("Dequeued: %d\n", temp->data);
    *front = (*front)->next;
    free(temp);
    return *front;
}

void displayQueue(struct Node* front) {
    printf("Queue: ");
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}

//MENU

int main() {
    struct Node *stackTop = NULL;
    struct Node *front = NULL, *rear = NULL;

    int choice, val;

    while (1) {
        printf("\n------ MENU ------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Enqueue\n");
        printf("4. Dequeue\n");
        printf("5. Display Stack\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                stackTop = push(stackTop, val);
                break;

            case 2:
                stackTop = pop(stackTop);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                rear = enqueue(rear, val, &front);
                break;

            case 4:
                front = dequeue(&front);
                if (front == NULL) rear = NULL;
                break;

            case 5:
                displayStack(stackTop);
                break;

            case 6:
                displayQueue(front);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
