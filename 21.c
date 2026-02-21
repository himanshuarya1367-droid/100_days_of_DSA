#include <stdio.h>
#include <stdlib.h>

/* Definition of node */
struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    /* Read number of nodes */
    scanf("%d", &n);

    /* Create linked list */
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;      /* First node */
            temp = head;
        } else {
            temp->next = newNode; /* Link new node */
            temp = newNode;
        }
    }

    /* Traverse and print linked list */
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
