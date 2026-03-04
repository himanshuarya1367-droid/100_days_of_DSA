#include <stdio.h>
#include <stdlib.h>

#define MAX 1000   /* Maximum stack size */

int main()
{
    int stack[MAX];
    int n, m;
    int top = -1;
    int i;

    /* Read number of elements */
    scanf("%d", &n);

    /* Push elements */
    for(i = 0; i < n; i++)
    {
        scanf("%d", &stack[++top]);
    }

    /* Read number of pops */
    scanf("%d", &m);

    /* Pop elements */
    for(i = 0; i < m; i++)
    {
        if(top >= 0)
            top--;
    }

    /* Print remaining stack from top to bottom */
    for(i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}
