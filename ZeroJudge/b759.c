#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[1000001];
    int len, i;
    scanf("%s", buf);
    len = strlen(buf);
    for (i = 0; i < len; i++) {
        printf("%.*s%.*s\n", len - i, buf + i, i, buf);
    }
    return 0;
}