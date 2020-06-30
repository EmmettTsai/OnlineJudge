#include <stdio.h>

int main(void) {
    int n, m, i, j, c, arr1[10000], arr2[10000];
    scanf("%d %d", &n, &m);
    while (n--) {
        c = 0;
        for (i = 0; i < m; i++)
            scanf("%d", &arr1[i]);
        for (i = 0; i < m; i++)
            scanf("%d", &arr2[i]);
        i = j = 0;
        while (1) {
            while (arr1[i] < arr2[j] && ++i < m);
            if (i == m)
                break;
            if (arr1[i] == arr2[j]) {
                c++;
                if (++i == m)
                    break;
            }
            while (arr1[i] > arr2[j] && ++j < m);
            if (j == m)
                break;
            if (arr1[i] == arr2[j]) {
                c++;
                if (++j == m)
                    break;
            } 
        }
        printf("%d\n", c);
    }
    return 0;
}