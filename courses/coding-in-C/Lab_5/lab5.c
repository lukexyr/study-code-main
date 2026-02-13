#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void particle_simulation(int *pField, int *pTemp, int size) {

    for (int i = 0; i < size; i++) {
        pTemp[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        if (pField[i] == 1) {
            if (rand() % 2 == 0) {
                if (i > 0) {
                    pTemp[i - 1] ^= 1;
                } else {
                    pTemp[i] = 1;
                }
            } else {
                if (i < size - 1) {
                    pTemp[i + 1] ^= 1;
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        pField[i] = pTemp[i];
        printf("%d ", pField[i]);
    }

    printf("\n");
}

int main() {

    int field[] = {0,1,0,1,0,1,0,0,0,0};
    int size = sizeof(field) / sizeof(field[0]);

    int *pTemp = calloc(size, sizeof(field[0]));
    if (!pTemp) return 1;

    srand(time(NULL));

    particle_simulation(field, pTemp, size);
    particle_simulation(field, pTemp, size);
    particle_simulation(field, pTemp, size);

    free(pTemp);
    return 0;
}
