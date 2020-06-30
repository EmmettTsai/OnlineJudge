#include <stdio.h>

int main(void) {
    char str[1024], ch, max_ch, *ptr;
    int max, len;
    while (scanf("%s", str) != EOF) {
        max = 0;
        ch = 0;
        ptr = str;
        while (*ptr) {
            for (ch = *ptr, len = 1; *++ptr == ch; len++);
            if (len > max) {
                max = len;
                max_ch = ch;
            }
        }
        printf("%c %d\n", max_ch, max);
    }
    return 0;
}