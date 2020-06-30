#include <stdio.h>

int main(void) {
    char name[100];
    while (scanf("%[^\n]\n", name) != EOF) {
        printf("Go, %s, go go\n", name);
    }
    return 0;
}