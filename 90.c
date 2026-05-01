#include <stdio.h>

#define MAX 1000

int boards[MAX];
int n, k;

// Function to check if painting is possible within given time
int isPossible(int maxTime) {
    int painters = 1;
    int currSum = 0;
    int i;

    for(i = 0; i < n; i++) {
        // If single board exceeds maxTime ? not possible
        if(boards[i] > maxTime)
            return 0;

        if(currSum + boards[i] <= maxTime) {
            currSum += boards[i];
        } else {
            painters++;
            currSum = boards[i];

            if(painters > k)
                return 0;
        }
    }
    return 1;
}

int findMinTime() {
    int i;
    int low = 0, high = 0;
    
    // Calculate sum and max
    for(i = 0; i < n; i++) {
        high += boards[i];
        if(boards[i] > low)
            low = boards[i];
    }

    int result = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(mid)) {
            result = mid;
            high = mid - 1; // try smaller time
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int i;

    scanf("%d %d", &n, &k);

    for(i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", findMinTime());

    return 0;
}
