#include <stdio.h>

int N, M, map[100][100];

int cal(int i, int j, int k) {
	if (map[i][j] <= 0)
		return 0;
	map[i][j] = -map[i][j];
	if (i > 0)
		k += cal(i - 1, j , map[i - 1][j]);
	if (j < M - 1)
		k += cal(i , j + 1, map[i][j + 1]);
	if (i < N - 1)
		k += cal(i + 1, j, map[i + 1][j]);
	if (j > 0)
		k += cal(i , j - 1, map[i][j - 1]);
	return k;
}

int main(void)
{
	int i, j, count, t, max;

	while (scanf("%d %d", &N, &M) != EOF) {
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				scanf("%d", &map[i][j]);

		count = 0;
		max = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (map[i][j] > 0) {
					count++;
					t = cal(i, j, map[i][j]);
					if (t > max)
						max = t;
				}
			}
		}
		printf("%d\n%d\n", count, max);
	}
	return 0;
}
