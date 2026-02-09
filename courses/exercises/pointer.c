#include <stdio.h>

int main() {

    int myNumbers[5] = {1,2,3,4,5};

    int *pNumber1 = myNumbers +1;
    int *pNumber2 = myNumbers + ((sizeof(myNumbers) / sizeof(myNumbers[0])) -1);
    int difference = pNumber2 - pNumber1;
 
    printf("First pointer: %p \n", pNumber1);
    printf("Second pointer: %p \n", pNumber2);
    printf("Difference: %d \n", difference);
}