#include <stdio.h>

int main(void) {
    unsigned char base = 0b10100111;
    unsigned char maskError = 0x80;
    unsigned char maskOverTemperature = 0x40;
    unsigned char maskUnderVoltage = 0x20;
    unsigned char value = 0x00;

    unsigned char resultError = base & maskError;
    unsigned char resultOverTemperature = base & maskOverTemperature;
    unsigned char resultUnderVoltage = base & maskUnderVoltage;

    value = value | (base << 4);
    value = value >> 4;

    printf("Base: %u\n", base);
    printf("Value: %u\n", value);  

    if (resultError) {
        printf("Error bit is set\n");
    } else {
        printf("Error bit is NOT set\n");
    }

    if (resultOverTemperature) {
        printf("OverTemperature bit is set\n");
    } else {
        printf("OverTemperature bit is NOT set\n");
    }

    if (resultUnderVoltage) {
        printf("UnderVoltage bit is set\n");
    } else {
        printf("UnderVoltage bit is NOT set\n");
    }

    return 0;
}
