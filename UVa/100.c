#include <stdio.h>

int compute_len(int n)
{
    int len = 1;
    while (n != 1)
    {   
        len++;
        n = n & 1 ? 3 * n + 1 : n >> 1;
    }   
    return len;
}

int main(void)
{
    int i, j, k, len, maxlen;
    while (scanf("%d %d", &i, &j) != EOF)
    {   
        printf("%d %d ", i, j); 
        if (i > j)
            i ^= j ^= i ^= j;
        maxlen = 0;
        for (k = i; k <= j; k++)
        {   
            len = compute_len(k);
            if (len > maxlen)
                maxlen = len;
        }   
        printf("%d\n", maxlen);
    }   
    return 0;
}
