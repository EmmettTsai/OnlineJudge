#include <stdio.h>

int main(void) {
    int n, m, i, min, max;
    while (scanf("%d", &n) != EOF) {
        min = 1001;
        max = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &m);
            if (m < min)
                min = m;
            if (m > max)
                max = m;
        }
        printf("%d %d %s\n", min, max, (max - min + 1 == n ? "yes" : "no"));
    }
    return 0;
}