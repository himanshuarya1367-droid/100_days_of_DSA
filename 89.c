#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;
    int i;

    for(i = 0; i < n; i++) {
        // If a single book has more pages than maxPages
        if(arr[i] > maxPages)
            return 0;

        if(pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            students++;
            pagesSum = arr[i];

            if(students > m)
                return 0;
        }
    }
    return 1;
}

// Function to find minimum pages
int findMinPages(int arr[], int n, int m) {
    int i;
    int sum = 0, max = 0;

    for(i = 0; i < n; i++) {
        sum += arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

    int low = max;
    int high = sum;
    int result = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller value
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, m, i;

    scanf("%d %d", &n, &m);

    int arr[1000]; // fixed size for old compiler

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if(m > n) {
        printf("-1\n"); // Not possible
        return 0;
    }

    int result = findMinPages(arr, n, m);

    printf("%d\n", result);

    return 0;
}
