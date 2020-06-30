#include <stdio.h>

int main(void) {
    int R, C, M, A[10][10], i, j, k, s, m, n, a, b, x, y, *I, *J;
    while (scanf("%d %d %d", &R, &C, &M) != EOF) {
        for (i = 0; i < R; i++)
            for (j = 0; j < C; j++)
                scanf("%d", &A[i][j]);
        for (s = i = 0; i < M; i++) {
            scanf("%d", &k);
            s = k ? 7 - s : ((s + 1 - 4) % 4 + (s == 3 ? 0 : 4));
        }
        C--;
        R--;
        switch (s) {
            case 0: a = 0; m = R; b = 0; n = C; I = &i; J = &j; break;
            case 1: a = C; m = 0; b = 0; n = R; I = &j; J = &i; break;
            case 2: a = R; m = 0; b = C; n = 0; I = &i; J = &j; break;
            case 3: a = 0; m = C; b = R; n = 0; I = &j; J = &i; break;
            case 4: a = 0; m = C; b = 0; n = R; I = &j; J = &i; break;
            case 5: a = 0; m = R; b = C; n = 0; I = &i; J = &j; break;
            case 6: a = C; m = 0; b = R; n = 0; I = &j; J = &i; break;
            case 7: a = R; m = 0; b = 0; n = C; I = &i; J = &j; break;
        }
        //printf("s=%d\n", s);
        printf("%d %d\n", a + m + 1, b + n + 1);
        x = a > m ? -1 : 1;
        y = b > n ? -1 : 1;
        for (i = a; i != m + x; i += x) {
            for (j = b; j != n + y; j += y)
                printf("%.*s%d", (j != b), " ", A[*I][*J]);
            puts("");
        }
        //printf("(%d,%d,%d) (%d,%d,%d)\n", a, m, x, b, n, y);
    }
    return 0;
}

/*
→
右旋90: i首尾對調，i,j對調
翻    : i首尾對調

←
左旋90: i,j對調，i首尾對調
翻    : i首尾對調

  0R0C
  ambn
0 ambn
1 nbam
2 manb
3 bnma
4 bnam
5 amnb
6 nbma
7 mabn

0 0R0C
1 C00R
2 R0C0
3 0CR0
4 0C0R
5 0RC0
6 C0R0
7 R00C
*/