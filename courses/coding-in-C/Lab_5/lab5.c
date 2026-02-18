#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        printf("%d", pField[i]);
    }

    printf("\n");
}

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Wrong number of arguments!\n");
        return 1;
    }

    int size = strlen(argv[1]);

    int *field = calloc(size, sizeof(int));
    if (!field) return 1;

    for (int i = 0; i < size; i++) {
        if (argv[1][i] == '0')
            field[i] = 0;
        else if (argv[1][i] == '1')
            field[i] = 1;
        else {
            printf("Invalid character!\n");
            free(field);
            return 1;
        }
    }

    int *pTemp = calloc(size, sizeof(int));
    if (!pTemp) {
        free(field);
        return 1;
    }

    srand(time(NULL));

    particle_simulation(field, pTemp, size);

    free(pTemp);
    free(field);

    return 0;
}
