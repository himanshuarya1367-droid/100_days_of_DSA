//Read a string and check if it is a palindrome using two-pointer comparison.
#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, j;
    int flag = 1;

    scanf("%s", s);

    i = 0;
    j = strlen(s) - 1;

    while (i < j)
    {
        if (s[i] != s[j])
        {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    if (flag == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}

