#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int field[] = {0,1,0,1,0,1,0,0,0,0};
    int size = sizeof(field) / sizeof(*field);

    int temp[size];
    int *pField = field;
    int *pTemp  = temp;

    srand(time(NULL));

    for (int i = 0; i < size; i++)
        *(pTemp + i) = 0;

    for (int i = 0; i < size; i++) {
        if (*(pField + i) == 1) {

            if (rand() % 2 == 0) {
                if (i > 0)
                    *(pTemp + i - 1) = 1;
            } else {
                if (i < size - 1)
                    *(pTemp + i + 1) = 1;
            }
        } 
    }

    for (int i = 0; i < size; i++)
        *(pField + i) = *(pTemp + i);

    for (int i = 0; i < size; i++)
        printf("%d", *(pField + i));
}
