#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%*d");
    while (scanf("%d %d", &n, &m) != EOF) {
        printf("%d\n", (n / 3) * (m / 3));
    }
    return 0;
}