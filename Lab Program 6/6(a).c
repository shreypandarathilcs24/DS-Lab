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

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    struct Node* temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n, val;

    printf("\nEnter number of nodes for List 1: ");
    scanf("%d", &n);
    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head1, val);
    }

    printf("\nEnter number of nodes for List 2: ");
    scanf("%d", &n);
    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head2, val);
    }

    printf("\nList 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    printf("\nSorting List 1...\n");
    sortList(head1);
    display(head1);

    printf("\nSorting List 2...\n");
    sortList(head2);
    display(head2);

    printf("\nReversing List 1...\n");
    reverseList(&head1);
    display(head1);

    printf("\nReversing List 2...\n");
    reverseList(&head2);
    display(head2);

    printf("\nConcatenating List 1 and List 2...\n");
    struct Node* result = concatenate(head1, head2);
    display(result);

    return 0;
}
