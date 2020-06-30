#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%*d%d", &a);
    printf("%d", a);
    while (scanf("%d", &b) != EOF) {
        printf(" %d", b - a);
        a = b;
    }
    return 0;
}