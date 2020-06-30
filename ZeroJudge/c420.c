#include <stdio.h>

int main(void) {
    int n, m, i, j;
    scanf("%d", &n);
    m = 2 * n - 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            putchar(j >= m / 2 - i && j < m / 2 + i + 1 ? '*' : '_');
        puts("");
    }
    return 0;
}