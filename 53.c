#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue for level order traversal
struct Queue {
    struct Node* node;
    int hd;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* current = queue[front++];

        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }
    return root;
}

// Vertical order traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Queue queue[MAX];
    int front = 0, rear = 0;

    int column[MAX][MAX];
    int size[MAX] = {0};

    int offset = MAX / 2;  // to handle negative HD

    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    while (front < rear) {
        struct Queue temp = queue[front++];

        struct Node* node = temp.node;
        int hd = temp.hd;

        column[hd + offset][size[hd + offset]++] = node->data;

        if (node->left) {
            queue[rear].node = node->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

        if (node->right) {
            queue[rear].node = node->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    // Print vertical columns
    int i, j;
    for (i = 0; i < MAX; i++) {
        if (size[i] > 0) {
            for (j = 0; j < size[i]; j++)
                printf("%d ", column[i][j]);
            printf("\n");
        }
    }
}

int main() {
    int n, i;
    int arr[MAX];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
