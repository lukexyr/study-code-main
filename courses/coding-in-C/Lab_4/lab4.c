#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char checkPalindrom(char* palindrom, int size) {
    for (int i = 0; i <= size/2; i++)
    {
        if(tolower(palindrom[i]) != tolower(palindrom[size-i-1])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    const int BUFFER_SIZE = 100;
    char *palindrom = (char*)malloc(BUFFER_SIZE);

    printf("Please enter your word (max. 100 characters): ");
    if(scanf("%99s", palindrom) != 1) return 1;

    if(checkPalindrom(palindrom, strlen(palindrom))) {
        printf("Your provided word '%s' is a palindrome \n", palindrom);
    } else {
        printf("Your provided word '%s' is NOT a palindrome \n", palindrom);
    }
    
    free(palindrom);
    return 0;
}



