#include <stdio.h>

int main(void) {
    int n, top = -1, num[100000];
    scanf("%d");
    while (scanf("%d", &n) != EOF) {
        if (n == 1) {
            if (top >= 0)
                top--;
        }
        else if (n == 2) {
            if (top >= 0)
                printf("%d\n", num[top]);
        }
        else
            scanf("%d", &num[++top]);
    }
    return 0;
}