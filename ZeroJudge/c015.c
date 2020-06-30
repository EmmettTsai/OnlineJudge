//Lychrel Number

#include <stdio.h>

int main(void) {
    int n, d, i;
    char num[11];
    scanf("%*d");
    while (scanf("%s", num) != EOF) {
        n = 0;
        for (d = 0; num[d]; d++)
            num[d] -= '0';
        d--;
        while (1) {
            for (i = 0; i <= d / 2; i++)
                num[i] = num[d - i] += num[i];
            for (i = 0; i <= d; i++) {
                num[i + 1] += num[i] / 10;
                num[i] %= 10;
            }
            if (num[i]) {
                d++;
                num[i + 1] = 0;
            }
            n++;
            for (i = 0; i <= d / 2; i++)
                if (num[i] != num[d - i])
                    break;
            if (i == d / 2 + 1)
                break;
        }
        for (i = 0; i <= d; i++)
            num[i] += '0';
        num[i] = 0;
        printf("%d %s\n", n, num);
    }
    return 0;
}