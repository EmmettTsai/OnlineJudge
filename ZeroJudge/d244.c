#include <stdio.h>

int main(void) {
    unsigned int n, a = 0, b = 0, c;
    while (scanf("%u", &n) != EOF) {
        c = n & 0x55555555U;
        a += c - (a & (c * 2)) / 2 * 3;
        c = n & 0xAAAAAAAAU;
        b += c / 2 - (b & c) / 2 * 3;
    }
    printf("%u\n", b + a / 2);
    return 0;
}