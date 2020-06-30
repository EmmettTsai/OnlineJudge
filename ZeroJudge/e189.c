#include <stdio.h>

int main(void) {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        while (1)
        {
            for (m = 0; n; n >>= 2) {
                if (n & 1)
                    m++;
                if (n & 2)
                    m--;
            }
            if (m < 0)
                m = -m;
            if (m < 2)
                break;
            n = m;
        }
        puts(m ? "NO" : "YES");
    }
    return 0;
}