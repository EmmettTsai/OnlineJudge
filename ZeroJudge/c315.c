#include <stdio.h>

int main(void) {
    int a, b, x = 0, y = 0;
    scanf("%*d");
    while (scanf("%d %d", &a, &b) != EOF) {
        switch (a) {
            case 0: y += b; break;
            case 1: x += b; break;
            case 2: y -= b; break;
            case 3: x -= b; break;
        }
    }
    printf("%d %d", x, y);
    return 0;
}