#include <stdio.h>

int main(void) {
    int n, m, i, j, x1, y1, x2, y2, rect[501][501] = { 0 };

    while (scanf("%d %d", &n, &m) != EOF) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                scanf("%d", &rect[i][j]);
                rect[i][j] += rect[i][j - 1] + rect[i - 1][j] - rect[i - 1][j - 1];
            }
        }

        for (i = 0; i < m; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            printf("%d\n", rect[x2][y2] + rect[x1 - 1][y1 - 1] - rect[x2][y1 - 1] - rect[x1 - 1][y2]);
        }
    }
    return 0;
}
