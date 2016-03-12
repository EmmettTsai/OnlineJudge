#include <stdio.h>

int n, max;
char map[4][5];

int verify(int y, int x) {
	int i, j;
	if (map[y][x] == 'X')
		return 0;
	for (i = y - 1; i >= 0; i--) {
		if (map[i][x] == 'o')
			return 0;
		if (map[i][x] == 'X')
			break;
	}
	for (j = x - 1; j >= 0; j--) {
		if (map[y][j] == 'o')
			return 0;
		if (map[y][j] == 'X')
			break;
	}
	return 1;
}

void recursive(int y, int x, int count) {
	int j;
	if (y < n) {
		for (j = x; j < n; j++) {
			if (j < 0)
				recursive(y + 1, -1, count);
			else if (verify(y, j)) {
				map[y][j] = 'o';
				recursive(y, j + 1, count + 1);
				recursive(y + 1, -1, count + 1);
				map[y][j] = '.';
			}
		}
	} else {
		if (count > max)
			max = count;
	}
}

int main(void)
{
	int i, j, k;

	while (scanf("%d", &n), n != 0) {
		for (i = 0; i < n; i++)
			scanf("%s", map[i]);
		max = 0;
		recursive(0, -1, 0);
		printf("%d\n", max);
	}
	return 0;
}
