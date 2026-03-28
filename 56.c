#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create new node */
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Queue structure for level order tree creation */
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[++q->front];
}

/* Check mirror */
int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;

    if (t1 == NULL || t2 == NULL)
        return 0;

    if (t1->data != t2->data)
        return 0;

    return isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

/* Check symmetric */
int isSymmetric(struct Node* root) {
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

int main() {
    int n, i, val;
    struct Node* nodes[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        if (val == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(val);
    }

    /* Build tree using array representation */
    for (i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if (leftIndex < n)
                nodes[i]->left = nodes[leftIndex];

            if (rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    if (isSymmetric(nodes[0]))
        printf("YES");
    else
        printf("NO");

    return 0;
}
