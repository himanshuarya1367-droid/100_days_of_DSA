#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Simple queue for nodes
struct Node* queue[1000];
int front = 0, rear = 0;

// Push to queue
void enqueue(struct Node* node) {
    queue[rear++] = node;
}

// Pop from queue
struct Node* dequeue() {
    return queue[front++];
}

// Check empty
int isEmpty() {
    return front == rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (!isEmpty() && i < n) {
        struct Node* curr = dequeue();

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Find height
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    int i;
    for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("%d\n", height(root));

    return 0;
}
