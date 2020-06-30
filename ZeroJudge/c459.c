#include <stdio.h>
#include <math.h>

int main(void) {
    int b, N, d, i, x, y;
    char buf[9] = { 0 };
    while (scanf("%d %s", &b, buf) != EOF) {
        for (d = 0; buf[d]; d++);
        N = 0;
        x = 0;
        for (i = 0; i < d; i++) {
            y = buf[i] - '0';
            N = b * N + y;
            x += (int)pow(y, d);
        }
        puts(N == x ? "YES" : "NO");
    }
    return 0;
}