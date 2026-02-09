#include <stdio.h>

int main() {
    char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int size = (sizeof(alpha) / sizeof(alpha[0])) -1;

    for(int i = 8; i >= 0; i--) {
        for(int j = 0; j <= size; j++) {
            printf("%c%i ", alpha[j], i);
        }
        printf("\n");
    }
}


