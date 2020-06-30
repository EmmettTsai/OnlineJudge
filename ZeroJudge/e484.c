#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i;
    scanf("%d", &n);
    if (n == 2)
        puts("yes");
    else if (n % 2 == 0)
        puts("no");
    else
    {
        for (i = ((int)sqrt(n)) | 1; i > 1 && n % i != 0; i -= 2);
        puts(i == 1 ? "yes" : "no");
    }
    return 0;
}