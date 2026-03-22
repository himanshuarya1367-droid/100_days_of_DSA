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
    
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

/* Insert into BST */
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

/* Search in BST */
int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }
    
    if (root->data == key) {
        return 1;
    }
    
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    struct Node* root = NULL;
    int n, i, value, key;

    /* Number of elements */
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    /* Insert elements */
    printf("Enter values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    /* Search key */
    printf("Enter value to search: ");
    scanf("%d", &key);

    if (search(root, key)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}
