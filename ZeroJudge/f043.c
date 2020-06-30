#include <stdio.h>

int main(void) {
    int R, A;
    scanf("%d %d", &R, &A);
    if (R == A)
    {
        if (A < 6)
            printf("%d+3=%d\n", A - 3, R);
        else
            printf("3+%d=%d\n", A - 3, R);
    }
    else if (A < R - A)
        printf("%d+%d=%d\n", A, R - A, R);
    else
        printf("%d+%d=%d\n", R - A, A, R);
    return 0;
}