#include <stdio.h>

int main(void) {
	int N, L, T, R, B, i, j, max, sum, arr[101][101] = {0};

	while (scanf("%d", &N) != EOF) {
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				scanf("%d", &arr[i][j]);
		for (i = 1; i <= N; i++)
			for (j = 2; j <= N; j++)
				arr[i][j] += arr[i][j - 1];
		for (j = 1; j <= N; j++)
			for (i = 2; i <= N; i++)
				arr[i][j] += arr[i - 1][j];

		max = -128;
		for (L = 1; L <= N; L++) {
			for (T = 1; T <= N; T++) {
				for (R = L; R <= N; R++) {
					for (B = T; B <= N; B++) {
						sum = 0;
						sum = (arr[B][R] - arr[B][L - 1]) - (arr[T - 1][R] - arr[T - 1][L - 1]);
						if (sum > max)
							max = sum;
					}
				}
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
