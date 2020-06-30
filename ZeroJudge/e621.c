#include <stdio.h>

int main(void) {
    int A, B, C, i, m;
    scanf("%*d");
    while (scanf("%d %d %d", &A, &B, &C) != EOF) {
        m = 0;
        for (i = A + 1; i < B; i++) {
            if (i % C != 0) {
                printf("%d ", i);
                m = 1;
            }
        }
        if (m == 0)
            puts("No free parking spaces.");
        else
            puts("");
    }
    return 0;
}