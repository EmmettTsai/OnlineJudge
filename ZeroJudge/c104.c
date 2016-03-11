#include <stdio.h>

int map[8][8], arr[8], max, sum;

void queen(int row, int left, int right, int level) {
	int pos, p, i, j;
	if (row != 0xFF) {
		pos = (~(row | left | right)) & 0xFF;
		while (pos) {
			p = pos & (-pos);
			pos -= p;
			for (i = 0, j = p; j >>= 1; i++);
			arr[level] = i;
			queen(row + p, (left + p) << 1, (right + p) >> 1, level + 1);
		}
	} else {
		sum = 0;
		for (i = 0; i < 8; i++)
			sum += map[i][arr[i]];
		if (sum > max)
			max = sum;
	}
}

int main(void)
{
	int i, j, k;
	scanf("%d", &k);
	while (k--) {
		for (i = 0; i < 8; i++)
			for (j = 0; j < 8; j++)
				scanf("%d", &map[i][j]);
		max = 0;
		queen(0, 0, 0, 0);
		printf("%d\n", max);
	}
	return 0;
}
