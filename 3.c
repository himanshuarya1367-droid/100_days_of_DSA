//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>

// Define a maximum limit for the array size
// This is necessary for older compilers that do not support Variable Length Arrays
#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, k;
    int i;
    int comparisons;
    int found_index;

    // 1. Read array size (n)
    scanf("%d", &n);

    // 2. Read array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Read the key (k)
    scanf("%d", &k);

    // Initialize variables
    comparisons = 0;
    found_index = -1; // -1 indicates "Not Found"

    // 4. Perform Linear Search
    for (i = 0; i < n; i++) {
        comparisons++; // Count the comparison we are about to make
        
        if (arr[i] == k) {
            found_index = i;
            break; // Stop the loop as soon as the element is found
        }
    }

    // 5. Output the results
    if (found_index != -1) {
        printf("Found at index %d\n", found_index);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}
