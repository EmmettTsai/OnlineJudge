#include <stdio.h>

int main(void) {
    char buf[4097] = "", *ptr;
    int k, len, count = 0, max_count = 0;
    scanf("%d", &k);
    while (scanf("%4096s", buf) != EOF) {
        ptr = buf;
        do {
            len = 0;
            while (*ptr && *ptr < 'a') {
                ptr++;
                len++;
            }
            if (len >= k)
                count++;
            if (count > max_count)
                max_count = count;
            if (len != k)
                count = len > k;
            if (*ptr == 0)
                break;

            len = 0;
            while (*ptr && *ptr > 'Z') {
                ptr++;
                len++;
            }
            if (len >= k)
                count++;
            if (count > max_count)
                max_count = count;
            if (len != k)
                count = len > k;
        } while (*ptr != 0);
    }
    printf("%d\n", k * max_count);
    return 0;
}