#include <stdio.h>

int main(void) {
    int n, len, i, j, k;
    scanf("%d");
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", 2 * (n - 1) + (n < 3));
        i = n < 3 ? 0 : 1;
        do {
            j = 0;
            do {
                k = 0;
                do {
                    printf("%d %d %d\n", j, k, n - i);
                } while (i != 0 && (k += i) <= i);
            } while (i != 0 && (j += i) <= i);
        } while (++i <= (n - 1) / 2);
        if (n % 2 == 0) {
            len = n / 2;
            printf(
                "0 0 %d\n"
                "%d %d %d\n",
                len,
                len, len, len);
        }
    }
    return 0;
}