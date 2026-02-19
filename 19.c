//Given an array of integers, find two elements whose sum is closest to zero.
#include <stdio.h>
#include <stdlib.h>   /* for abs() */

int main() {
    int n, i, j;
    int arr[100];
    int minSum, sum;
    int x, y;

    /* Input size */
    printf("Enter number of elements: ");
    scanf("%d", &n);

    /* Input elements */
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* Initialize with first pair */
    minSum = abs(arr[0] + arr[1]);
    x = arr[0];
    y = arr[1];

    /* Check all pairs */
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            sum = abs(arr[i] + arr[j]);

            if (sum < minSum) {
                minSum = sum;
                x = arr[i];
                y = arr[j];
            }
        }
    }

    /* Output result */
    printf("Pair whose sum is closest to zero: %d %d\n", x, y);

    return 0;
}

