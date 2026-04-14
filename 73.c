#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int freq[26] = {0};
    int i;

    // Input string
    scanf("%s", str);

    // Count frequency of each character
    for(i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }

    // Find first non-repeating character
    for(i = 0; str[i] != '\0'; i++) {
        if(freq[str[i] - 'a'] == 1) {
            printf("%c\n", str[i]);
            return 0;
        }
    }

    // If no non-repeating character found
    printf("$\n");

    return 0;
}
