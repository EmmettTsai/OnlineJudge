#include <stdio.h>

int main(void) {
    char name[100];
    while (scanf("%s", name) != EOF) {
        name[0] += 'A' - 'a';
        printf("%s\n", name);
    }
    return 0;
}