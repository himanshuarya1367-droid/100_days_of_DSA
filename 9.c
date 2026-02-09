//A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>

int main() {
    char str[100];
    int i, j;
    char temp;

    scanf("%s", str);

    for(i = 0; str[i] != '\0'; i++);
    int len = i;

    for(i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("%s\n", str);

    return 0;
}

