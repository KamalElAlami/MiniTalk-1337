#include <stdio.h>

void printBits(char c) {
    int i = 7;
    while(i >= 0) {
        if ((c >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
        i--;
    }
    printf("\n");
}

int main() {
    char character = 'c';
    printf("Bit representation of '%c': ", character);
    printBits(character);
    return 0;
}