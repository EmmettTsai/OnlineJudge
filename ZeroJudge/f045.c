#include <stdio.h>

int main(void) {
    char num[10];
    int count[10] = { 0 }, i, j;
    scanf("%s", num);
    for (i = 0; i < 10; i++)
        count[num[i] - '0']++;
    for (i = 9; count[i] == 0; i--);
    j = i;
    if (count[i] == 1)
        while (count[--i] == 0);
    if (i * i + j * j == (num[8] - '0') + 10 * (num[7] - '0') + 100 * (num[6] - '0'))
        printf("Good Morning!\n");
    else
        printf("SPY!\n");

    return 0;
}