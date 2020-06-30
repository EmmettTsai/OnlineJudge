#include <stdio.h>

int main(void) {
    char name[256];
    scanf("%[^\n]\n", &name);
    printf("Hey %s\n", name);
    return 0;
}