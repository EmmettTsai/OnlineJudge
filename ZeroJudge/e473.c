#include <stdio.h>
#include <math.h>

int main(void) {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        if (a == 0)
            puts("1");
        else
            printf("%d\n", (int)(b * log10(a)) + 1);
    }
    return 0;
}