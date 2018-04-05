#include <stdio.h>

/* 10^15 = 38D7EA4C68000 , 50 bits */

#define SHIFT(x, s, m) (((x) >> (s)) & (m)) | (((x) & (m)) << (s));
unsigned long bitsReverse64(unsigned long n) {
    n = SHIFT(n, 32, 0x00000000FFFFFFFFUL);
    n = SHIFT(n, 16, 0x0000FFFF0000FFFFUL);
    n = SHIFT(n,  8, 0x00FF00FF00FF00FFUL);
    n = SHIFT(n,  4, 0x0F0F0F0F0F0F0F0FUL);
    n = SHIFT(n,  2, 0x3333333333333333UL);
    n = SHIFT(n,  1, 0x5555555555555555UL);
    return n;
}

unsigned long popcount64(unsigned long n) {
    n -= (n >> 1) & 0x5555555555555555UL;
    n = (n & 0x3333333333333333UL) + ((n >> 2) & 0x3333333333333333UL);
    return (((n + (n >> 4)) & 0xF0F0F0F0F0F0F0FUL) * 0x101010101010101UL) >> 56;
}

/*
 * Let reverse(n) is the bits reverse of n in binary
 *
 * EX:
 * reverse(6) = reverse(110b)  =  011b = 3
 * reverse(9) = reverse(1001b) = 1001b = 9
 *
 *
 * Let f(n) is the set bits count of n
 *
 * EX:
 * f(6) = f(110b) = 2
 * f(9) = f(1001b) = 2
 *
 * Let g(n) = f(n + reverse(n))
 * if input is N then output is sum(g(m), m = 1 .. N)
 *
 * EX:
 * input:
 * 6
 *
 * output:
 * 11
 *
 **/

/*
 * 1 <= N
 * n = floor(log2(N))
 *
 * Formula variable available range:
 * 0 <= n
 *
 * Original formula:
 * F0(n) = 2^((n-4)/2)*((-1)^n+1)+2^((n-5)/2)*((-1)^(n+1)+1)+2^(n-1)*n+2^(n-2)-1
 *
 * return value:
 * sum(g(m), m = 1 .. (2^n - 1))
 *
 **/
long F0(long n) {
    return (((1L << ((n + 2) / 2)) + (1L << n) * (2 * n + 1)) >> 2) - !!n;
}

/*
 * 1 <= N
 * n = floor(log2(N)) + 1
 *
 * Formula variable available range:
 * 4 <= n
 * 0 <= i <= n
 * 0 <= j < 2^n
 * 0 <= k < i
 * i <= (n - 4) / 2
 *
 * Original formula:
 * P(j,k) = 1 if (k+1)-th bit from LSB is set, otherwise 0
 * F1(n,i,j) = 2^(n-i-3)*(n+1)+2^(n-2*i-5)+((-1)^(n)+1)*2^((n-8)/2)*(2^(-i)*(3-n)+2*n-4*i-8)+((-1)^(n)-1)*2^((n-5)/2-i)*(2^(1+i)-1)
 *             +sum(P(j, k)*(+2^(n-3+k-2*i)+((-1)^(n)+1)*2^((n-8)/2-k)*(4+2*i-2*k-n)+((-1)^(n)-1)*(2^((n-5)/2-k)-2^((n-3)/2-k))), k = 0 .. i-1)
 *
 * if n is odd:
 * F1(n, i, j) = 2^(n-i-3)*(n+1)+2^(n-2*i-5)+2^((n-3)/2-i)-2^((n-1)/2)
 *               +(sum(P(j, k)*(+2^(n-2*i+k-3)+2^((n-3)/2-k)), k = 0 .. i-1))
 *
 * if n is even:
 * F1(n, i, j) = 2^(n-i-3)*(n+1)+2^(n-2*i-5)+2^((n-6)/2-i)*(3-n)+2^((n-4)/2)*(n-2*i-4)
 *               +(sum(P(j, k)*(+2^(n-2*i+k-3)+2^((n-6)/2-k)*(2*(i-k+2)-n)), k = 0 .. i-1))
 *
 * return value:
 * sum(g(m), m = (2^(n-1)+(2*j)*2^(n-2-i)) .. (2^(n-1)+(2*j+1)*2^(n-2-i)-1))
 *
 **/
long F1(long n, long i, long j) {
    long k, X = (1L << (n - i - 2)) * (n + 1) + (1L << (n - 2 * i - 4));

    if (n & 1) {
        X += (1L << ((n - 1) / 2 - i)) - (1L << ((n + 1) / 2));
        for (k = 0; j; k++, j >>= 1)
            if (j & 1) X += (1L << (n - 2 * i + k - 2)) + (1L << ((n - 1) / 2 - k));
    } else {
        X += (1L << ((n - 4) / 2 - i)) * (3 - n) + (1L << ((n - 2) / 2)) * (n - 2 * i - 4);
        for (k = 0; j; k++, j >>= 1)
            if (j & 1) X += (1L << (n - 2 * i + k - 2)) + (1L << ((n - 4) / 2 - k)) * (2 * (i - k + 2) - n);
    }
    return X >> 1;
}

int main(void) {
    long n, i, j, d, X, D, P, Q;
    scanf("%ld", &n);

    for (i = n, D = 1; i >>= 1; D++);
    X = F0(D - 1);
    P = D < 4 ? -1 : (D - 4) / 2;
    Q = n & (~((1L << (D - P - 2)) - 1));

    for (i = 0; i <= P; i++) {
        if ((n >> (D - 2 - i)) & 1) {
            j = (n >> (D - i - 1)) & ((1L << i) - 1);
            X += F1(D , i, j);
        }
    }

    d = 64 - D;
    for (i = Q; i <= n; i++)
        X += popcount64(i + (bitsReverse64(i) >> d));

    printf("%ld\n", X);
    return 0;
}
