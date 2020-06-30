#include <stdio.h>

int main(void) {
    int x, y;
    scanf("%d");
    while (scanf("%d %d", &x, &y) != EOF) {
        x = 100 - x - y;
        if (x > 0 && x <= 30)
            printf("sad!\n");
        else if(x > 30 && x <= 60)
            printf("hmm~~\n");
        else if(x > 60 && x < 100)
            printf("Happyyummy\n");
        else
            printf("evil!!\n");
    }
    return 0;
}