#include <stdio.h>

int main(void) {
    unsigned x, y, l, t, r, b;
    scanf("%u %u %u %u %u %u", &x, &y, &l, &b, &r, &t);
    if (x < l)
        x = l - x;
    else if (x > r)
        x -= r;
    else
        x = 0;
    if (y < b)
        y = b - y;
    else if (y > t)
        y -= t;
    else
        y = 0;
    printf("%u", x + y);
    return 0;
}