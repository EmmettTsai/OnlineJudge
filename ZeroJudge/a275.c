#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000001], *ptr;
    int ascii[127];
    while (1) 
    {   
        gets(str);
        if (!strncmp(str, "STOP!!", 6)) 
            break;
        memset(&ascii[33], '\0', sizeof(int) * (127 - 33));
        for (ptr = str; *ptr; ptr++)
            ascii[*ptr]++;
        *(ptr - 1) = '\0';
        gets(str);
        if (*ptr != '\0' || *(ptr - 1) == '\0')
            puts("no");
        else
        {   
            for (ptr = str; *ptr; ptr++)
                if (--ascii[*ptr] < 0)
                    break;
            puts(*ptr ? "no" : "yes");
        }   
    }   
    return 0;
}
