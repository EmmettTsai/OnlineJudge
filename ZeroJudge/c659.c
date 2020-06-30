#include <stdio.h>

int main(void) {
    char conjunction[20], word[256];
    scanf("%s %s", conjunction, word);
    printf("%s", word);
    while (scanf("%s", word) != EOF)
        printf(" %s %s", conjunction, word);
    return 0;
}