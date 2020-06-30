#include <stdio.h>

int main(void) {
    char buf[50 * 20], *ptr;
    int n;
    buf[0] = ' ';
    scanf("%[^\n]\n%d", buf + 1, &n);
    for (ptr = buf + 1; *ptr; ptr++);
    while (1) {
        if (*--ptr == ' ') {
            *ptr = 0;
            if (--n == 0)
                break;
        }
    }
    puts(ptr + 1);
    return 0;
}