#include <stdio.h>

int main(void) {
    char n[33], m[33], *ptr;
    int b1, b2, num, i, j;
    m[32] = 0;
    while (scanf("%s %d %d", n, &b1, &b2) != EOF) {
        if (b1 == b2) {
            puts(n);
            continue;
        }
        num = i = 0;
        while (n[++i]);
        for (i--, j = 1; i >= 0; i--, j *= b1)
            num += (n[i] - (n[i] < 'A' ? '0' : 'A' - 10)) * j;
        ptr = &m[32];
        while (num) {
            *--ptr = num % b2;
            *ptr += *ptr < 10 ? '0' : 'A' - 10;
            num /= b2;
        }
        puts(ptr);
    }
    return 0;
}