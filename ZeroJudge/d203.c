#include <stdio.h>

int main(void) {
	int n, i, j, k, sum, arr[16], symbol[17] = {0};
	int digit[7] = {10, 100, 1000, 10000, 100000, 1000000};
	
	for (i = 0; i < 16; i++)
		arr[i] = i + 1;

	while (scanf("%d", &n) != EOF) {
		symbol[0] = 1;
		for (i = 1; i <= n; i++)
			symbol[i] = 0;
		do {
			sum = 0;
			j = arr[n - 1];
			k = j > 9 ? 1 : 0;
			for (i = n - 1; i >= 0; i--) {
				switch (symbol[i]) {
				case 0: // ' '
					if (k > n / 2 - 2)
						goto next;
					j += arr[i - 1] * digit[k];
					k += arr[i - 1] > 9 ? 2 : 1;
					break;
				case 1: // '+'
					sum += j;
					j = arr[i - 1];
					k = j > 9 ? 1 : 0;
					break;
				case 2: // '-'
					sum -= j;
					j = arr[i - 1];
					k = j > 9 ? 1 : 0;
					break;
				}
			}
			if (sum == 0) {
				for (i = 1; i <= n; i++) {
					printf("%d", arr[i - 1]);
					if (i == n)
						putchar('\n');
					else if (symbol[i] == 0)
						putchar(' ');
					else if (symbol[i] == 1)
						putchar('+');
					else if (symbol[i] == 2)
						putchar('-');
				}
			}
next:
			for (i = n - 1; i >= 0; i--) {
				if (symbol[i] < 2) {
					symbol[i]++;
					break;
				} else {
					symbol[i] = 0;
				}
			}
		} while (symbol[0] == 1);
	}

	return 0;
}
