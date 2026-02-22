#include <stdio.h>
#include <stdlib.h>

/* Define node structure */
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, i, value, count = 0;

    /* Read number of nodes */
    scanf("%d", &n);

    /* Create linked list */
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    /* Traverse list: print elements and count nodes */
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        count++;
        temp = temp->next;
    }

    /* (Optional) If you want to print count, uncomment below */
    /* printf("\nTotal nodes = %d", count); */

    return 0;
}
