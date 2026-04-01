#include <stdio.h>

int isMinHeap(int arr[], int n)
{
    int i;

    /* Only need to check non-leaf nodes */
    for (i = 0; i <= (n - 2) / 2; i++)
    {
        /* Check left child */
        if (arr[i] > arr[2 * i + 1])
            return 0;

        /* Check right child if exists */
        if ((2 * i + 2 < n) && arr[i] > arr[2 * i + 2])
            return 0;
    }

    return 1;
}

int main()
{
    int n, i;
    int arr[100];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter level-order traversal:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (isMinHeap(arr, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
