#include <stdio.h>
#include <string.h>

long long arr[50] = { 0 };
long long fun(int n, int m, long long N, long long L)
{
    long long A, B, C, D, a, b, c, d, p1, p2;
    int x, y, bound, odd, xy00, xy01, xy10, xy11, x_known, y_known;

    memset(arr, 0, sizeof(arr));
    odd = (n & 1) == 1;

    p1 = 1LL << (n / 2 + L - n);
    p2 = 1LL << ((n - 1) / 2 + L - n);
    for (int w = odd ? 1 : 2; w <= n; w += 2)
    {
        x_known = m >= (n - w + 2) / 2;
        y_known = m >= (n + w) / 2;
        x = !!(N & p1);
        y = !!(N & p2);
        xy00 = (!x_known || x == 0) && (!y_known || y == 0);
        xy01 = (!x_known || x == 0) && (!y_known || y == 1);
        xy10 = (!x_known || x == 1) && (!y_known || y == 0);
        xy11 = (!x_known || x == 1) && (!y_known || y == 1);

        bound = odd ? (w / 2) : (w - 1);
        if (w < 3)
        {
            A = 1;
            B = C = D = 0;
            arr[0] = odd ? 0 : 1;
        }
        else
        {
            A = a;
            B = b;
            C = c;
            D = d;
        }
        a = b = c = d = 0;
        if (xy00)
        {
            a += A + B;
            c += C + D;
        }

        if (xy01 && w > 1)
        {
            a += A;
            b += B;
            c += C + 2 * A;
            d += D + B;
        }

        if (xy10 && w > 1)
        {
            a += A;
            b += B;
            c += C + 2 * A;
            d += D + B;
        }

        if (xy11)
        {
            b += A + B;
            d += (C + D + A + B) + arr[0];
            for (int i = 2; i < bound; i++)
                d -= (i - 1) * arr[i];
        }

        // xy01, xy10
        {
            int scale = xy01 + xy10;

            if (!odd)
            {
                arr[w] = scale * arr[w - 2];
                arr[w - 2] = 0;
            }

            for (int i = w / 2; i > 0; i--)
                arr[i] = scale * arr[i - 1];
        }

        // xy00, xy11
        {
            int scale = xy00 + xy11;
            arr[0] = scale * (A + B);
        }

        p1 <<= 1;
        p2 >>= 1;
    }

    return c + d;
}

int main(void)
{
    long long n, pos, res = 0;
    int i, j, L = 0;

    scanf("%lld", &n);

    for (pos = 1; pos <= n; pos <<= 1)
        L++;

    for (i = 1; i < L; i++)
    {
        res += fun(i, 1, n, L);
        pos = 1LL << (L - 1 - i);
        if (n & pos)
            res += fun(L, i + 1, n & ~pos, L);
    }

    res += fun(L, L, n, L);

    printf("%lld\n", res);

    return 0;
}
