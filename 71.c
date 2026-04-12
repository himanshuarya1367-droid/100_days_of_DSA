#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define SIZE 100   // max size (can adjust)

int table[SIZE];
int m; // actual hash table size

// Hash function
int hash(int key) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }
    printf("Hash table full\n");
}

// Search using quadratic probing
int search(int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key) + i * i) % m;

        if (table[index] == EMPTY) {
            return 0; // not found
        }

        if (table[index] == key) {
            return 1; // found
        }

        i++;
    }
    return 0;
}

int main() {
    int n, i;
    char op[10];
    int key;

    // Input table size
    scanf("%d", &m);

    // Initialize table
    for (i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    // Number of operations
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
