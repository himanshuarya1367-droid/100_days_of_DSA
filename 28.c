#include <stdio.h>
#include <stdlib.h>

/* Structure definition */
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    /* Read number of nodes */
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        /* Allocate memory */
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    /* Make it circular */
    temp->next = head;

    /* Traverse circular linked list */
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}
