#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int visited[26] = {0};  // for 'a' to 'z'
    int i;

    // Input string
    scanf("%s", s);

    for(i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if(visited[index] == 1) {
            // First repeated character found
            printf("%c", s[i]);
            return 0;
        }

        visited[index] = 1;
    }

    // No repeated character
    printf("-1");

    return 0;
}
