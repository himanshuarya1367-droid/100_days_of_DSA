#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create new node */
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Build tree from level order */
struct Node* buildTree(int arr[], int n, int index)
{
    if (index >= n || arr[index] == -1)
        return NULL;

    struct Node* root = createNode(arr[index]);
    root->left = buildTree(arr, n, 2 * index + 1);
    root->right = buildTree(arr, n, 2 * index + 2);

    return root;
}

/* Mirror the tree */
void mirror(struct Node* root)
{
    struct Node* temp;

    if (root == NULL)
        return;

    temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

/* Inorder traversal */
void inorder(struct Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n, i;
    int arr[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    mirror(root);

    inorder(root);

    return 0;
}
