#include <stdio.h>

int main(void) {
    int a, b, c, max;
    scanf("%*d%d%d", &a, &b);
    for (max = c = a - b; scanf("%d", &a) != EOF; b = a)
        if ((c = c > 0 ? b - a + c : b - a) > max)
            max = c;
    printf("%d\n", max);
    return 0;
}
