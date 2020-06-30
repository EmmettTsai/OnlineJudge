#include <stdio.h>

int main(void) {
    int n, i, ans;
    while (scanf("%d", &n) != EOF) {
        ans = 1;
        for (i = 1; i < n; i++)
            ans += i;
        printf("%d\n", ans);
    }
    return 0;
}