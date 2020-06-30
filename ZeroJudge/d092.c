#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    if (*(unsigned long*)b > *(unsigned long*)a)
        return 1;
    if (*(unsigned long*)b < *(unsigned long*)a)
        return -1;
    return 0;
}

int main(void) {
    unsigned n, i;
    unsigned long a, b, num[1000];
    while (scanf("%u", &n), n != 0) {
        for (i = 0; i < n; i++) {
            scanf("%lu %lu", &a, &b);
            num[i] = ((a + b) << 32) + (a > b ? '>' : (a < b ? '<' : '='));
        }
        qsort(num, n, sizeof(unsigned long), cmp);
        for (i = 0; i < n; i++)
            printf("%c%u ",
                (char)*(unsigned*)(&num[i]),
                *((unsigned*)(&num[i]) + 1)
            );
        putchar('\n');
    }
    return 0;
}