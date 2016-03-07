#include <stdio.h>

#define LEN  (1 + 1 * 9 + 2 * (99 - 10 + 1) + 3 * (999 - 100 + 1) + 4 * (2015 - 1000 + 1))
#define SIZE (1 + 1 * 9 + 2 * (99 - 10 + 1) + 3 * (999 - 100 + 1) + 4 * (2020 - 1000 + 1))

int main(void)
{
	int y, i, j, k, m;
	char *ptr1, *ptr2, *ptr3, arr[SIZE];
	char map[10][10];

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			map[i][j] = i + j;
			if (map[i][j] > 9)
				map[i][j] -= 9;
		}
	}

	ptr1 = &arr[1 + 1 * 9];
	ptr2 = &arr[1 + 1 * 9 + 2 * (99 - 10 + 1)];
	ptr3 = &arr[1 + 1 * 9 + 2 * (99 - 10 + 1) + 3 * (999 - 100 + 1)];
	for (i = 1; i <= 9; i++) {
		arr[i] = i;
		for (j = 0; j <= 9; j++) {
			*(ptr1++) = i;
			*(ptr1++) = j;
			for (k = 0; k <= 9; k++) {
				*(ptr2++) = i;
				*(ptr2++) = j;
				*(ptr2++) = k;
				if (i < 2 || (i == 2 && j == 0 && k < 2)) {
					for (m = 0; m <= 9; m++) {
						*(ptr3++) = i;
						*(ptr3++) = j;
						*(ptr3++) = k;
						*(ptr3++) = m;
					}
				}
			}
		}
	}

	for (i = 1; i < LEN; i++) {
		for (j = LEN; j > i; j--) {
			arr[j] = map[arr[j - 1]][arr[j]];
		}
	}

	while (scanf("%d", &y) != EOF) {
		if (y < 10)
			k = y;
		else if (y < 100)
			k = 1 * 9 + 2 * (y % 100 - 10 + 1);
		else if (y < 1000)
			k = 1 * 9 + 2 * (99 - 10 + 1) + 3 * (y % 1000 - 100 + 1);
		else
			k = 1 * 9 + 2 * (99 - 10 + 1) + 3 * (999 - 100 + 1) + 4 * (y % 10000 - 1000 + 1);
		printf("%d\n", arr[k]);
	}
	return 0;
}
