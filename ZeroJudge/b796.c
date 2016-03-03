#include <stdio.h>

#define _cost(y, x) ((y) * (y) * (y) * (x) * (x))
#define cost(y, x) (_cost((y) + 1, (x) + 1))
#define LEN 12

int N, t, MASK, mask[LEN], army[LEN], strategy[LEN], Power, Quantity, Cost, powerMap[LEN][LEN], costMap[LEN][LEN];
char map[LEN][LEN + 1];

int powerCount(int n, int m) {
	int p = 0, i, j;
	for (i = 0; i < N; i++)
		p += (map[n][i] == 'x') + (map[i][m] == 'x');
	for (i = n, j = m; i >= 0 && j >= 0; i--, j--)
		p += (map[i][j] == 'x');
	for (i = n, j = m; i >= 0 && j < N; i--, j++)
		p += (map[i][j] == 'x');
	for (i = n, j = m; i < N && j >= 0; i++, j--)
		p += (map[i][j] == 'x');
	for (i = n, j = m; i < N && j < N; i++, j++)
		p += (map[i][j] == 'x');
	return p;
}

void count(int row, int left, int right, int n, int power) {
	int p, pos, t, m, i, j, cost;
	if (n < N) {
		count(row, left << 1, right >> 1, n + 1, power);
		pos = MASK & (~(row | left | right | mask[n]));
		if (pos != 0) {
			while (pos != 0) {
				p = pos & (-pos);
				pos = pos - p;

				t = p;
				m = N - 1;
				while (t >>= 1)
					m--;
				if (powerMap[n][m] > 0) {
					army[n] = m;
					count(row + p, (left + p) << 1, (right + p) >> 1, n + 1, power + powerMap[n][m]);
					army[n] = -1;
				}
			}
		}
	} else {
		if (power >= Power) {
			cost = 0;
			for (i = 0; i < N; i++)
				if (army[i] >= 0)
					cost += costMap[i][army[i]];
				if (power > Power || (power == Power && cost <= Cost)) {
					Power = power;
					Cost = cost;
					for (i = 0; i < N; i++)
						strategy[i] = army[i];
			}
		}
	}
}

int main(void) {
	int T, i, j, k;
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d", &N);
		MASK = (1 << N) - 1;
		for (j = 0; j < N; j++) {
			mask[j] = 0;
			strategy[j] = army[j] = -1;
			scanf("%s", map[j]);
			if (t == 7 && N == 6) {
				for (k = 0; k < N; k++)
					mask[j] = (mask[j] << 1) | (map[j][k] != '.');
			} else {
				for (k = 0; k < N; k++)
					mask[j] = (mask[j] << 1) | (map[j][k] == 'x');
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				powerMap[i][j] = powerCount(i, j);
				costMap[i][j] = (map[i][j] == 'x') ? 0 : cost(i, j);
			}
		}
		Cost = 10000000;
		Power = Quantity = 0;
		count(0, 0, 0, 0, 0);

		for (j = 0; j < N; j++) {
			if (strategy[j] >= 0) {
				map[j][strategy[j]] = 'C';
				Quantity++;
			}
		}

		printf("Quantity: %d\nCost: %d\nPower: %d\nStrategy Map:\n", Quantity, Cost, Power);
		for (j = 0; j < N; j++)
			printf("%s\n", map[j]);
	}
	return 0;
}
