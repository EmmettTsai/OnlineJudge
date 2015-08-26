#include <stdio.h>

int main(void)
{
    char buf[1000], *pos;
    int words, flag;
    while(scanf(" %[^\n]", buf) != EOF)
    {   
        words = 0;
        flag = 0;
        for (pos = buf; *pos != '\0'; pos++)
        {   
            if ((*pos >= 'A' && *pos <= 'Z') || (*pos >= 'a' && *pos <= 'z'))
            {   
                if (flag)
                    continue;
                else
                {   
                    flag = 1;
                    ++words;
                }   
            }   
            else if (flag)
                flag = 0;
        }   
        printf("%d\n", words);
    }   
    return 0;
}
