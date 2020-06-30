#include <stdio.h>

int main(void) {
    int N, i, M = 0, num[10001];
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
        scanf("%d", &num[i]);
    M = 0;
    for (i = 1; i <= N; i += num[N])
        M += num[i];
    M %= N;
    if (M == 0)
        printf("%d %d\n", N, num[N]);
    else
        printf("%d %d\n", M, num[M]);
    return 0;
}