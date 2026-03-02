#include <stdio.h>
#include <stdlib.h>

/* Define structure for polynomial term */
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

/* Function to create a new node */
struct Node* createNode(int c, int e) {
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    return newNode;
}

/* Function to insert node at end */
struct Node* insertEnd(struct Node* head, int c, int e) {
    struct Node* temp;
    struct Node* newNode;

    newNode = createNode(c, e);

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

/* Function to print polynomial */
void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        /* Print coefficient */
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        }
        else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        }
        else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }
}

/* Main function */
int main() {
    int n, i;
    int coeff, exp;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insertEnd(head, coeff, exp);
    }

    printPolynomial(head);

    return 0;
}
