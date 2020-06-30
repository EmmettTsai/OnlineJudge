#include <stdio.h>

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            puts("0");
        else {
            n %= 9;
            printf("%d\n", n == 0 ? 9 : n);
        }
    }
    return 0;
}