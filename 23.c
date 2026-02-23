#include <stdio.h>
#include <stdlib.h>

/* Definition of node */
struct Node {
    int data;
    struct Node *next;
};

/* Create a new node */
struct Node* createNode(int value) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert node at end */
struct Node* insertEnd(struct Node *head, int value) {
    struct Node *temp, *newNode;
    newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

/* Merge two sorted lists */
struct Node* mergeLists(struct Node *l1, struct Node *l2) {
    struct Node *merged = NULL, *last = NULL, *temp;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            temp = l1;
            l1 = l1->next;
        } else {
            temp = l2;
            l2 = l2->next;
        }

        if (merged == NULL) {
            merged = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    if (l1 != NULL)
        last->next = l1;
    else
        last->next = l2;

    return merged;
}

/* Print linked list */
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, i, value;
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    struct Node *merged = NULL;

    /* Input first list */
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }

    /* Input second list */
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }

    /* Merge lists */
    merged = mergeLists(list1, list2);

    /* Output */
    printList(merged);

    return 0;
}
