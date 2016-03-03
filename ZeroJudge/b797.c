#include <stdio.h>
#include <math.h>

#ifndef max
#define max(a, b) ((a)>(b)?(a):(b))
#endif

#define NN 40000
#define DIGITS 9
#define BOUND 1000000000

int main(void)
{
	int i, j, jj, k, T, N, DP[NN + 1][6] = {0};

	for (i = 0; i <= NN; i++)
		DP[i][0] = DP[i][1] = 1;

	for (j = 2; j <= (int) sqrt((double)NN); j++) {
		jj = j * j;
		for (i = jj; i <= NN; i++) {
			DP[i][0] = max(DP[i][0], DP[i - jj][0]);
			for (k = 1; k <= DP[i][0]; k++) {
				DP[i][k] += DP[i - jj][k];
			}
			for (k = 1; k <= DP[i][0]; k++) {
				if (DP[i][k] >= BOUND) {
					if (k == DP[i][0]) {
						DP[i][0]++;
					}
					DP[i][k + 1] += DP[i][k] / BOUND;
					DP[i][k] %= BOUND;
				}
			}
		}
	}

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		i = DP[N][0];
		printf("%d", DP[N][i]);
		while (--i > 0)
			printf("%0*d", DIGITS, DP[N][i]);
		putchar('\n');
	}
	return 0;
}
