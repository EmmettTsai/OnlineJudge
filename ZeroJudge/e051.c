#include <stdio.h>

int main(void) {
    char buf[1001], *ptr;
    scanf("%s", buf);
    for (ptr = &buf[2]; *ptr; ptr++)
        *(ptr - 1) = '_';
    puts(buf);
    return 0;
}