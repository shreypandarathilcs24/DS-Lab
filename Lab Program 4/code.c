#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createList(int n) {
    struct node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Enter a valid number\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory Allocation Failed...\n");
            return;
        }

        printf("Enter the data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    printf("\nLinked List created...\n");
}

void InsertAtBeginning(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void InsertAtEnd(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Node inserted at the end...\n");
}

void InsertAtAny(int data, int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed...\n");
        return;
    }

    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at the beginning\n");
        return;
    }

    struct node *temp = head;
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d\n", position);
}

void Display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n, data, pos;
    int exit = 1;

    while (exit) {
        printf("\nAvailable operations...\n");
        printf("1:Create linked list, 2:Insert at beginning, 3:Insert at any position, 4:Insert at end, 5:Display list, 6:Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes to create: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                InsertAtBeginning(data);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                InsertAtAny(data, pos);
                break;

            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                InsertAtEnd(data);
                break;

            case 5:
                Display();
                break;

            case 6:
                exit = 0;
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
