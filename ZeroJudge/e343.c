#include <stdio.h>

int main(void) {
    int w, h;
    scanf("%d%d", &w, &h);
    printf("%.1f", 10000. * w / (h * h));
    return 0;
}