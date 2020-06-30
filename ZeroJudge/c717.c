#include <stdio.h>

int main(void) {
    char str[256];
    scanf("%[^\n]\n", str);
    printf("%s %s", str, str);
    return 0;
}