#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

// Function to create and insert node at end
void createList(int value) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->prev = newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

// Insert new node to the LEFT of a specific node (before a value)
void insertLeft(int key, int value) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->prev = newnode->next = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found!\n", key);
        return;
    }

    // Insert before the head
    if (temp == head) {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return;
    }

    // Insert in middle
    newnode->next = temp;
    newnode->prev = temp->prev;
    temp->prev->next = newnode;
    temp->prev = newnode;
}

// Delete a node by value
void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    // search key
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node %d not found!\n", key);
        return;
    }

    // if head is to be deleted
    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    // last node
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        free(temp);
        return;
    }

    // middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// Display contents
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val, key;

    while (1) {
        printf("1. Create List, 2. Insert to the left of the node, 3. Delete by value, 4. Display, 5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                createList(val);
                break;

            case 2:
                printf("Insert before which value? ");
                scanf("%d", &key);
                printf("Enter new value: ");
                scanf("%d", &val);
                insertLeft(key, val);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteNode(key);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
