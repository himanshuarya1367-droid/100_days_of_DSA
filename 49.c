#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* Function to create a new node */
struct Node* createNode(int value) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

/* BST Insert function */
struct Node* insert(struct Node* root, int value) {
    
    /* If tree is empty */
    if(root == NULL)
        return createNode(value);
    
    /* Insert into left subtree */
    if(value < root->data)
        root->left = insert(root->left, value);
    
    /* Insert into right subtree */
    else if(value > root->data)
        root->right = insert(root->right, value);
    
    /* Ignore duplicates */
    
    return root;
}

/* Inorder traversal */
void inorder(struct Node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, i, value;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    
    printf("\nInorder Traversal (Sorted): ");
    inorder(root);
    
    return 0;
}
