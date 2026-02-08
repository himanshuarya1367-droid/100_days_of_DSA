#include <stdio.h>

long power(int a, int b)
{
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}

int main()
{
    int a, b;
    long result;

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    result = power(a, b);

    printf("%ld", result);

    return 0;
}

