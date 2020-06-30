#include <stdio.h>

int F(int x) {
    if (x == 1)
        return 1;
    if (x % 2 == 0)
        return F(x / 2);
    return F(x - 1) + F(x + 1);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", F(n));
    return 0;
}