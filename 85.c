#include <stdio.h>

#define MAX 100

void merge(int arr[], int left, int mid, int right) {
    int temp[MAX];
    int i = left, j = mid + 1, k = left;

    // Merge two sorted parts
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left half
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements of right half
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy back to original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;

        mergeSort(arr, left, mid);      // Left half
        mergeSort(arr, mid + 1, right); // Right half

        merge(arr, left, mid, right);   // Merge
    }
}

int main() {
    int arr[MAX], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
