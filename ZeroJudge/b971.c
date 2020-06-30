#include <stdio.h>

int main(void) {
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    if (a == b || d == 0)
        printf("%d\n", a);
    else {
        for (; a != b; a += d)
            printf("%d ", a);
        printf("%d\n", b);
    }
    return 0;
}