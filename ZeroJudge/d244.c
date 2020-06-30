#include <stdio.h>

int main(void) {
    unsigned long n, a = 0;
    while (scanf("%lu", &n) != EOF) {
        n = ((n & 0x55555555UL) << 33) | (n & 0xAAAAAAAAUL);
        a += (n - (a & n) * 3) / 2;
    }
    printf("%lu\n", (a & 0xAAAAAAAAUL) | (a >> 33));
    return 0;
}