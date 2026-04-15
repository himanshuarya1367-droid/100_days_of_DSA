#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    
    printf("Enter number of votes: ");
    scanf("%d", &n);
    
    char names[100][50];   // store input names
    int count[100] = {0};  // vote count
    int unique = 0;
    
    printf("Enter candidate names:\n");
    
    for(i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    
    // Count votes
    for(i = 0; i < n; i++) {
        int found = 0;
        
        for(j = 0; j < unique; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        
        if(!found) {
            strcpy(names[unique], names[i]);
            count[unique] = 1;
            unique++;
        }
    }
    
    // Find winner
    int maxVotes = count[0];
    char winner[50];
    strcpy(winner, names[0]);
    
    for(i = 1; i < unique; i++) {
        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
        else if(count[i] == maxVotes) {
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }
    
    // Output result
    printf("\nWinner: %s %d\n", winner, maxVotes);
    
    return 0;
}
