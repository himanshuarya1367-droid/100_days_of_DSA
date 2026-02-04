//Given an array of n integers, reverse the array in-place using two-pointer approach.
#include <stdio.h>

int main()
{
    int n, i;
    int arr[100];   // fixed size for old compiler
    int start, end, temp;

    // Read number of elements
    scanf("%d", &n);

    // Read array elements
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Two-pointer approach
    start = 0;
    end = n - 1;

    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    // Print reversed array
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

