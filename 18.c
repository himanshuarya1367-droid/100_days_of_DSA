#include <stdio.h>

int main() {
    int n, k, i;
    int arr[100], temp[100];

    /* Read number of elements */
    printf("Enter n: ");
    scanf("%d", &n);

    /* Read array elements */
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* Read k */
    printf("Enter k: ");
    scanf("%d", &k);

    /* Handle k greater than n */
    k = k % n;

    /* Copy last k elements to temp */
    for (i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    /* Shift remaining elements to the right */
    for (i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    /* Copy temp elements to front */
    for (i = 0; i < k; i++) {
        arr[i] = temp[i];
    }

    /* Print rotated array */
    printf("Rotated array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

