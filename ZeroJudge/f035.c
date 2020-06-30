#include <stdio.h>

int main(void) {
    char name[51], *ptr;
    scanf("%[^\n]\n", name);
    printf("%d", name[0]);
    for (ptr = name + 1; *ptr; ptr++)
        printf("_%d", *ptr);
    return 0;
}