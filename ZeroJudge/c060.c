#include <stdio.h>

int main(void)
{
    int n[9], i, neg;
    while (scanf("%d %d %d %d %d %d %d %d %d", &n[8], &n[7], &n[6], &n[5], &n[4], &n[3], &n[2], &n[1], &n[0]) != EOF)
    {
        for (i = 8; i > 0 && n[i] == 0; i--);
        if (i == 0)
            printf("%d\n", n[0]);
        else
        {
            if (i > 1)
            {
                if (n[i] == 1)
                    printf("x^%d", i);
                else if (n[i] == -1)
                    printf("-x^%d", i);
                else
                    printf("%dx^%d", n[i], i);
            }
            else
            {
                if (n[i] == 1)
                    printf("x");
                else if (n[i] == -1)
                    printf("-x");
                else
                    printf("%dx", n[i]);
            }

            while (--i >= 0)
            {
                if (n[i] == 0)
                    continue;
                if (neg = n[i] < 0)
                    n[i] = -n[i];
                if (n[i] == 1)
                {
                    if (i > 1)
                        printf(" %c x^%d", neg ? '-' : '+', i);
                    else
                        printf(" %c %c", neg ? '-' : '+', i == 1 ? 'x' : '1');
                }
                else
                {
                    if (i > 1)
                        printf(" %c %dx^%d", neg ? '-' : '+', n[i], i);
                    else
                        printf(" %c %d%s", neg ? '-' : '+', n[i], i == 1 ? "x" : "");
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
