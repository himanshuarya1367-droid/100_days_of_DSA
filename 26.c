#include <stdio.h>
#include <stdlib.h>

/* Structure for Doubly Linked List Node */
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

/* Function to insert at end */
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode;
    struct Node* temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    /* If list is empty */
    if (head == NULL) {
        return newNode;
    }

    /* Traverse to last node */
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

/* Function to print list forward */
void printList(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
}

int main() {
    int n, i, value;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printList(head);

    return 0;
}
