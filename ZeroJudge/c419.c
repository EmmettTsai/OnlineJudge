#include <stdio.h>

int main(void) {
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            putchar(i + j < n - 1 ? '_' : '*');
        puts("");
    }
    return 0;
}