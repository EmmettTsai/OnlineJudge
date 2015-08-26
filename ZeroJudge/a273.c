#include <stdio.h>

int main(void)
{
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF)
        printf("%s\n", (n==0 || (k!=0 && n%k==0)) ? "Ok!" : "Impossib1e!");
    return 0;
}
