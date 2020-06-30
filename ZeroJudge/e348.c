#include <stdio.h>

char no_gcd[] = "= =";

char* str_gcd(char* str1, char* str2) {
    char *ptr1 = str1, *ptr2 = str2;
    for ( ; *(ptr1) == *(ptr2) && *ptr1 && *ptr2; ptr1++, ptr2++);
    if (*ptr1 == 0 && *ptr2 == 0)
        return str1;
    if (*ptr1 == 0)
        return str_gcd(str1, ptr2);
    if (*ptr2 == 0)
        return str_gcd(ptr1, str2);
    return no_gcd;
}

int main(void) {
    char str1[1024], str2[1024], *ans;
    while (scanf("%s %s", str1, str2) != EOF)
        puts(str_gcd(str1, str2));
    return 0;
}