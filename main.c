#include <stdio.h>
#include <signal.h>

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
    kill(69969, SIGUSR1);
}