#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int preorder[MAX];
int inorder[MAX];
int preIndex = 0;

// Create new node
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Search root in inorder array
int search(int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree using preorder and inorder
struct Node* buildTree(int inStart, int inEnd) {
    if (inStart > inEnd)
        return NULL;

    // Pick current node from preorder
    int rootValue = preorder[preIndex++];
    struct Node* root = newNode(rootValue);

    // If only one node
    if (inStart == inEnd)
        return root;

    // Find root in inorder
    int inIndex = search(inStart, inEnd, rootValue);

    // Build left and right subtree
    root->left = buildTree(inStart, inIndex - 1);
    root->right = buildTree(inIndex + 1, inEnd);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter preorder traversal:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    printf("Enter inorder traversal:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = buildTree(0, n - 1);

    printf("Postorder traversal:\n");
    postorder(root);

    return 0;
}
