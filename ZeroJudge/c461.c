#include <stdio.h>

int main(void) {
    int a, b, c, d = 0;
    scanf("%d%d%d", &a, &b, &c);
    if ((!!a & !!b) == c)
        d |= puts("AND");
    if ((!!a | !!b) == c)
        d |= puts("OR");
    if ((!!a ^ !!b) == c)
        d |= puts("XOR");
    if (!d)
        puts("IMPOSSIBLE");
    return 0;
}