#include <stdio.h>

int main(void) {
    int n, a, b, c;
    scanf("%d\n%d %d %d", &n, &a, &b, &c);
    for ( ; n >= 1; n--) {
        if (n != a && n != b && n != c)
            printf("No. %d\n", n);
    }
    return 0;
}