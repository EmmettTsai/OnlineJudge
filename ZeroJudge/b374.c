#include <stdio.h>

int main(void) {
    int n, max_count = 0, count[30001] = { 0 };
    scanf("%d", &n);
    while (scanf("%d", &n) != EOF) {
        if (++count[n] > max_count)
            max_count = count[n];
    }
    for (n = 1; n < 30001; n++)
        if (count[n] == max_count)
            printf("%d %d\n", n, max_count);
    
    return 0;
}