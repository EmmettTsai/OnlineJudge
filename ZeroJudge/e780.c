#include <stdio.h>

int main(void) {
    char cmd[5];
    int x = 0, y, gift = 0;
    scanf("%*d");
    while (scanf("%s", cmd) != EOF) {
        switch (cmd[0])
        {
            case 'L': x--; break;
            case 'R': x++; break;
            default:
                scanf("%d", &y);
                if (x == y)
                    gift++;
                
        }
    }
    printf("%d\n", gift);
    return 0;
}