#include <stdio.h>

int main(void) {
    int G, A, H, W;
    scanf("%*d");
    while (scanf("%d %d %d %d", &G, &A, &H, &W) != EOF) {
        printf("%.2f\n", (G ? (13.7 * W + 5.0 * H - 6.8 * A + 66) : (9.6 * W + 1.8 * H - 4.7 * A + 655)));
    }
    return 0;
}