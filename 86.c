#include <stdio.h>

int main() {
    int n;
    int low, high, mid;
    int ans = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    low = 0;
    high = n;

    while (low <= high) {
        mid = low + (high - low) / 2;

        /* Avoid overflow: use division instead of mid*mid */
        if (mid <= n / mid) {
            ans = mid;        /* store possible answer */
            low = mid + 1;    /* move right */
        } else {
            high = mid - 1;   /* move left */
        }
    }

    printf("Integer square root: %d\n", ans);

    return 0;
}
