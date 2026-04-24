#include <stdio.h>

int lowerBound(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    int ans = n;   // default if not found

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] >= x)
        {
            ans = mid;        // possible answer
            right = mid - 1;  // move left
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int upperBound(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    int ans = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] > x)
        {
            ans = mid;        // possible answer
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n, i, x;
    int arr[100];   // fixed size for old compiler

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}
