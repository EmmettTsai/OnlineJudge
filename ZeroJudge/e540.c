#include <stdio.h>

int main(void) {
    char res[80], *ptr;
    int score, total;
    scanf("%*d");
    while (scanf("%s", res) != EOF) {
        total = 0;
        score = 0;
        for (ptr = res; *ptr; ptr++) {
            if (*ptr == 'O')
                total += ++score;
            else
                score = 0;
        }
        printf("%d\n", total);
    }
    return 0;
}