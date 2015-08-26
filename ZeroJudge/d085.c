#include <stdio.h>

int main(void)
{
    int n, x, i, ii, neg;

    while (scanf("%d", &n) != EOF)
    {   
        x = 1;
        if (neg = n < 0)
            n = -n; 
        else if (n == 0)
        {   
            puts("0");
            continue;
        }   

        while ((n & 3) == 0)
        {   
            x <<= 1;
            n >>= 2;
        }   
        for (i = 3; (ii = i * i) <= n; i += 2)
        {   
            while (n % ii == 0)
            {   
                x *= i;
                n /= ii; 
            }   
        }   
        if (x != 1)
            printf("%d", x); 

        if (n != 1)
            printf("_/%d", n); 

        puts(neg ? "i" : "");
    }   

    return 0;
}
