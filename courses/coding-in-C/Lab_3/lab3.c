#include <stdio.h>

float add(float fInput, float sInput) {
    return fInput + sInput;
}

float sub(float fInput, float sInput) {
    return fInput - sInput;
}

float mul(float fInput, float sInput) {
    return fInput * sInput;
}

float div(float fInput, float sInput) {
    return fInput / sInput;
}

int main() {
    float fInput, sInput, solution;
    char operation;

    printf("Input first Number: ");
    if(scanf("%f", &fInput) != 1) {printf("Invalid input"); return 1;}

    printf("Input second Number: ");
    if(scanf("%f", &sInput) != 1) {printf("Invalid input"); return 1;}

    printf("Input operation: ");
    scanf(" %c", &operation);

    switch (operation)
    {
        case '+':
            solution = add(fInput, sInput);
            break;

        case '-':
            solution = sub(fInput, sInput);
            break;

        case '*':
            solution = mul(fInput, sInput);
            break;

        case '/':
            if (sInput != 0) {
                solution = div(fInput, sInput);
            } else {
                printf("Cannot devide by zero! \n"); 
                return 1; }
            break;
        
        default:
            printf("Invalid operation! \n");
            return 0;
    }

    printf("The result of: %.2f %c %.2f = %.2f \n", fInput, operation, sInput, solution);
}