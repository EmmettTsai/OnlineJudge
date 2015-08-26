#include <stdio.h>

char num[] = "123456789";
#define NUM(i) (num[i] - '0')

void swap(char *a, char *b) 
{
    char tmp;
    tmp = *a; 
    *a = *b; 
    *b = tmp;
}

void perm(int n)
{
    int i;
    if (n == 1)
    {   
        if ((NUM(4) == 5) &&
            (NUM(1) % 2 == 0 && NUM(5) % 2 == 0) &&
            ((NUM(0) + NUM(1) + NUM(2)) % 3 == 0) &&
            ((NUM(3) + NUM(4) + NUM(5)) % 3 == 0) &&
            ((NUM(2) * 10 + NUM(3)) % 4 == 0) &&
            ((NUM(5) * 100 + NUM(6) * 10 + NUM(7)) % 8 == 0) &&
            (((NUM(4) - NUM(1)) * 100 + (NUM(5) - NUM(2)) * 10 + NUM(0) + NUM(6) - NUM(3)) % 7 == 0)) 
        {   
            printf("%s\n", num);
        }   
    }   
    else
    {   
        for (i = 0; i < n; i++)
        {   
            swap(&num[i], &num[n-1]);
            perm(n - 1); 
            swap(&num[i], &num[n-1]);
        }   
    }   
}

int main(void)
{
    perm(9);
    return 0;
}
