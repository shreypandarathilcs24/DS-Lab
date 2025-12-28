#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Employee {
    int key;        // 4-digit employee key
    int used;       // 0 = empty, 1 = occupied
};

struct Employee HT[MAX];
int m;

/* Hash Function */
int hash(int key) {
    return key % m;
}

/* Insert using Linear Probing */
void insert(int key) {
    int index = hash(key);
    int start = index;

    while (HT[index].used == 1) {
        index = (index + 1) % m;

        if (index == start) {
            printf("Hash Table is Full! Cannot insert %d\n", key);
            return;
        }
    }

    HT[index].key = key;
    HT[index].used = 1;
    printf("Inserted key %d at address %d\n", key, index);
}

/* Display Hash Table */
void display() {
    printf("\nHash Table Contents:\n");
    printf("Address\tKey\n");

    for (int i = 0; i < m; i++) {
        if (HT[i].used)
            printf("%d\t%d\n", i, HT[i].key);
        else
            printf("%d\t--\n", i);
    }
}

int main() {
    int n, key;

    printf("Enter number of memory locations (m): ");
    scanf("%d", &m);

    // Initialize hash table
    for (int i = 0; i < m; i++) {
        HT[i].used = 0;
    }

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter 4-digit employee key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
