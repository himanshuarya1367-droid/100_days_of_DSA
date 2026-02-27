#include <stdio.h>
#include <stdlib.h>

/* Definition of Node */
struct Node {
    int data;
    struct Node* next;
};

/* Create new node */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Append node to list */
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Get length of list */
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

/* Find intersection point */
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1, len2, diff, i;
    struct Node *temp1 = head1, *temp2 = head2;

    len1 = getLength(head1);
    len2 = getLength(head2);

    /* Align both lists */
    if (len1 > len2) {
        diff = len1 - len2;
        for (i = 0; i < diff; i++)
            temp1 = temp1->next;
    } else {
        diff = len2 - len1;
        for (i = 0; i < diff; i++)
            temp2 = temp2->next;
    }

    /* Traverse together */
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data == temp2->data) {
            return temp1->data;  /* Intersection found */
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return -1;  /* No intersection */
}

int main() {
    int n, m, i, value;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int result;

    /* Input first list */
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head1, value);
    }

    /* Input second list */
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &value);
        append(&head2, value);
    }

    result = findIntersection(head1, head2);

    if (result != -1)
        printf("%d\n", result);
    else
        printf("No Intersection\n");

    return 0;
}
