#include <stdio.h>

int main(void)
{
    int n, k, x, y;
    while (scanf("%d %d", &n, &k) != EOF)
    {   
        x = n;
        while (x >= k)
        {   
            y = x / k;
            n += y;
            x = y + x%k;
        }   
        printf("%d\n", n); 
    }   

    return 0;
}
