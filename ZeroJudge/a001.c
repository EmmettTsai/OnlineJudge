#include <stdio.h>

int main(void)
{
    char buf[100];
    while(scanf("%s", buf) != EOF)
    {   
        printf("hello, %s\n", buf);
    }   
    return 0;
}
