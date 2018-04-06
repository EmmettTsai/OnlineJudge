#include <stdio.h>
#include <stdlib.h>

int arr[30], n, m, j, k, c;

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void recursive(int sum, int i, int pos) {
    if (sum > m)
        return;
    if (i == n) {
        if (sum == m) {
            if (c)
                c = 0;
            k = 1 << (n - 1);
            for (j = 0; j < n; j++) {
                if (pos & k)
                    printf("%d ", arr[j]);
                pos <<= 1;
            }
            puts("");
        }
        return;
    }
    recursive(sum + arr[i], i + 1, (pos << 1) | 1);
    recursive(sum, i + 1, pos << 1);
}

int main(void) {
    int i, sum = 0;
    scanf("%d %d", &n, &m);

    c = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] <= m)
            c = 1;
        sum += arr[i];
    }
    if (c && sum >= m) {
        qsort(&arr, n, sizeof(int), cmp);
        recursive(0, 0, 0);
        if (c)
            puts("-1");
    } else {
        puts("-1");
    }

    return 0;
}
