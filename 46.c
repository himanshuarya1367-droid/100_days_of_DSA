#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Queue structure
struct Queue {
    int front, rear;
    int size;
    struct Node* arr[100];
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->size == 0;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    q->rear++;
    q->arr[q->rear] = node;
    q->size++;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    struct Node* temp = q->arr[q->front];
    q->front++;
    q->size--;
    return temp;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    struct Queue q;
    initQueue(&q);

    if (root == NULL)
        return;

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(&q, temp->left);

        if (temp->right != NULL)
            enqueue(&q, temp->right);
    }
}

// Build tree (simple manual build)
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;
}
