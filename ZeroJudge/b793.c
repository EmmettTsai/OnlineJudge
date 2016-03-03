#include <stdio.h>

int main(void)
{
	int T, N, i, j, k, s, u, arr[1000][2], tmp[1000], sum, MIN;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		for (j = 0; j < N; j++) {
			scanf("%d", &arr[j][0]);
			tmp[0] = arr[j][0];
			arr[j][1] = 0;
			for (k = 1; k < N; k++) {
				scanf("%d", &tmp[k]);
				arr[j][1] += (tmp[k] > tmp[k-1] ? tmp[k] - tmp[k-1] : tmp[k] - tmp[k-1] + N);
			}
		}
		MIN = N * N;
		for (j = 0; j < N; j++) {
			sum = 0;
			for (k = 0; k < N; k++) {
				s = k - j + arr[j][0];
				if (s < 1)
					s += N;
				else if (s > N)
					s -= N;
				u = s <= arr[k][0] ? arr[k][0] - s : arr[k][0] - s + N;
				if (u + arr[k][1] > sum)
					sum = u + arr[k][1];
			}
			if (sum < MIN)
				MIN = sum;
		}
		printf("%d\n", MIN);
	}
	return 0;
}
