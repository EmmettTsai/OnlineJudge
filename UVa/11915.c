#include <stdio.h>

#define MAX_N 1000
#define DIVISOR 1000000009
const int devisor_bit[16] = {0, 1, 2, 9, 11, 14, 15, 17, 19, 20, 23, 24, 25, 27, 28, 29};

int HookLengthFormula(int n, int *p) {
    int factorial[MAX_N + 1], power[30], i, j, m, a, b;
    long t;

    m = 0;
    for (i = 1; i <= n; i++)
        m += p[i];
    p[0] = m - n;
    p[n + 1] = 2;

    factorial[0] = 1;
    for (i = 0; i <= n; i++) {
        t = factorial[i];
        for (j = p[n - i + 1] + i; j <= p[n - i] + i; j++)
            t = (t * j) % DIVISOR;
        factorial[i + 1] = (int)t;
    }

    t = factorial[n + 1];
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
            t = (t * (p[i] - p[j] + j - i)) % DIVISOR;
    a = (int)t;

    t = 1;
    for (i = 1; i <= n; i++)
        t = (t * factorial[i]) % DIVISOR;
    b = (int)t;

    power[0] = b;
    for (i = 1; i < 30; i++)
        power[i] = (int)(((long)power[i - 1] * power[i - 1]) % DIVISOR);

    t = 1;
    for (i = 0; i < 16; i++)
        t = (t * power[devisor_bit[i]]) % DIVISOR;

    return (t * a) % DIVISOR;
}

int main(void) {
    int p[MAX_N + 2], n, i, T = 0;
    scanf("%*d");
    while (scanf("%d", &n) != EOF) {
        for (i = 1; i <= n; i++)
            scanf("%d", &p[i]);

        printf("Case %d: %d\n", ++T, HookLengthFormula(n, p));
    }
    return 0;
}
