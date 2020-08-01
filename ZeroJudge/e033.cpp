#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

typedef struct _StructA
{
    _StructA() {}
    _StructA(int _value, int _i, int _j) : value(_value), i(_i), j(_j) {}
    void set(int _value, int _i, int _j)
    {
        value = _value;
        i = _i;
        j = _j;
    }
    int value;
    int i;
    int j;
} StructA, *PStructA;

typedef struct _StructB
{
    _StructB() {}
    _StructB(int _count, int _mask) : count(_count), mask(_mask) {}
    void set(int _count, int _mask)
    {
        count = _count;
        mask = _mask;
    }
    int count;
    int mask;
} StructB, *PStructB;

inline bool compareA(StructA a, StructA b)
{
    return a.value < b.value;
}

inline bool compareB(PStructB a, PStructB b)
{
    return a->count < b->count;
}

inline int countBit(unsigned int n) {
    n = (n & 0x55555555u) + ((n >>  1) & 0x55555555u);
    n = (n & 0x33333333u) + ((n >>  2) & 0x33333333u);
    n = (n & 0x0f0f0f0fu) + ((n >>  4) & 0x0f0f0f0fu);
    n = (n & 0x00ff00ffu) + ((n >>  8) & 0x00ff00ffu);
    n = (n & 0x0000ffffu) + ((n >> 16) & 0x0000ffffu);
    return n;
}

inline bool hasSolution(int M, PStructB arrB[25])
{
    int i, mask = 0, min = 0, prev = 0;
    for (i = 0; i < M; i++)
    {
        prev = mask;
        mask |= arrB[i]->mask;
        if (prev != mask)
            min++;
        if (min > i)
            continue;
        min = countBit(mask);
        if (min <= i)
            return false;
    }
    return true;
}

int fun(int M, int matrix[24][24], int inf)
{
    int i, j, arrASize = M * M, val, l, r, m;

    StructA *cell;
    StructB rows[24], cols[24], *row, *col;
    StructA arrA[625 + 1];
    PStructB arrRow[25], arrCol[25], *it1, *it2;

    for (j = 0; j < M; j++) {
        bool skip = true;
        for (i = 0; i < M; i++) {
            if (matrix[i][j] > inf) {
                skip = false;
                break;
            }
        }
        if (skip)
            return 0;
    }

    for (i = 0; i < M; i++)
    {
        int skip = true;
        for (j = 0; j < M; j++) {
            arrA[i * M + j].set(matrix[i][j], i, j);
        }

        rows[i].count = M;
        rows[i].mask = (1 << M) - 1;
        arrRow[i] = &rows[i];

        cols[i].count = M;
        cols[i].mask = (1 << M) - 1;
        arrCol[i] = &cols[i];
    }
    std::sort(arrA, arrA + arrASize, compareA);

    for (i = 0; i < arrASize; )
    {
        val = arrA[i].value;

        do
        {
            cell = &arrA[i];
            row = &rows[cell->i];
            if (--row->count == 0)
                return val;
            row->mask &= ~(1 << cell->j);
            for (it1 = arrRow; *it1 != row && row->count >= (*it1)->count; it1++);
            if (*it1 != row)
            {
                for (it2 = it1 + 1; row != *it2; it2++);
                if ((*it1)->count > (*it2)->count)
                {
                    memmove(it1 + 1, it1, (it2 - it1) * sizeof(it1));
                    *it1 = row;
                }
            }

            col = &cols[cell->j];
            if (--col->count == 0)
                return val;
            col->mask &= ~(1 << cell->i);
            for (it1 = arrCol; *it1 != col && col->count >= (*it1)->count; it1++);
            if (*it1 != col)
            {
                for (it2 = it1 + 1; col != *it2; it2++);
                if ((*it1)->count > (*it2)->count)
                {
                    memmove(it1 + 1, it1, (it2 - it1) * sizeof(it1));
                    *it1 = col;
                }
            }
        } while (++i < arrASize && arrA[i].value == val);

        if (!hasSolution(M, arrRow))
            break;

        if (!hasSolution(M, arrCol))
            break;
    }
    return val;
}

int main(void) {
    int N, K, M, i, j, k, a, b, c, d, inf, res, offset_start, offset_bound;
    int resident[24][4], score[24][24], map[5], distance[4], dist[4], pos_rev[5];
    int perm[12][4], perm_count, perm_tmp[4];
    int* pos[5];
    char perm_pos[25];
    bool skip_flag[25], NO_SKIP[25] = { 0 };

    while (scanf("%d %d", &N, &K) != EOF) {
        M = N - K;
        for (i = 0; i < M; i++)
            for (j = 0; j < K; j++)
                scanf("%d", &resident[i][j]);

        for (i = 0; i < K; i++) {
            pos_rev[i] = K - i - 1;
            pos[i] = &pos_rev[K - i - 1];
        }
        pos_rev[K] = 0;

        perm_count = 0;
        for (i = 0; i < K; i++)
            perm_tmp[i] = i;

        do
        {
            if (K > 1)
            {
                if (perm_tmp[0] == K - 1)
                    break;
                if (perm_tmp[K - 1] < perm_tmp[0])
                    continue;
            }
            memcpy(perm[perm_count], perm_tmp, sizeof(int) * K);
            perm_count++;
        } while (std::next_permutation(perm_tmp, perm_tmp + K));
        for (i = 0; i < K; i++)
            perm[0][i] = i;

        inf = 0;

        while (1) {
            memset(perm_pos, 0, N);
            for (k = 0; k < K; k++)
                perm_pos[pos_rev[k]] = 1;

            offset_bound = N - pos_rev[0];
            for (c = 0; c < perm_count; c++) {
                a = 1;
                for (i = 0; i < M; i++) {
                    while (perm_pos[a])
                        a++;

                    for (k = 0; k < K; k++)
                        dist[k] = *pos[k] > a ? *pos[k] - a : a - *pos[k];
                    bool skip = true;
                    for (j = 0; j < M; j++) {
                        int min = 0x7fffffff;
                        for (k = 0; k < K; k++) {
                            const int tmp = dist[k] * resident[j][perm[c][k]];
                            if (tmp < min)
                                min = tmp;
                        }
                        score[i][j] = min;
                        if (min > inf)
                            skip = false;
                    }
                    skip_flag[i] = skip;

                    a++;
                }

                if (memcmp(skip_flag, NO_SKIP, M) == 0) {
                    res = fun(M, score, inf);
                    if (res > inf)
                        inf = res;
                }

                for (d = 1; d < offset_bound; d++)
                {
                    for (k = 0; k < K; k++)
                        dist[k] = *pos[k] + d;
                    // j: resident
                    bool skip = true;
                    for (j = 0; j < M; j++) {
                        int min = 0x7fffffff;
                        for (k = 0; k < K; k++) {
                            const int tmp = dist[k] * resident[j][perm[c][k]];
                            if (tmp < min)
                                min = tmp;
                        }
                        score[M - d][j] = min;
                        if (min > inf)
                            skip = false;
                    }
                    if (skip)
                        break;

                    skip_flag[M - d] = false;

                    if ((d < offset_bound - 1) && ((d >= pos_rev[0]) || (d < offset_bound - pos_rev[0])))
                        continue;

                    if (memcmp(skip_flag, NO_SKIP, M) == 0) {
                        res = fun(M, score, inf);
                        if (res > inf)
                            inf = res;
                    }
                }
            }

            pos_rev[0]++;
            for (i = 0; i < K; i++) {
                if (pos_rev[i] == N - i)
                    pos_rev[i + 1]++;
                else
                    break;
            }
            if (pos_rev[K - 1] == 1)
                break;
            for (j = i; j > 0; j--)
                pos_rev[j - 1] = pos_rev[j] + 1;
        }

        printf("%d\n", inf);
    }

    return 0;
}
