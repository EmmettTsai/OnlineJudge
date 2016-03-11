#include <stdio.h>

int n, used[9] = {0};
char num[9], result[9];

void recursive(int deep) {
	int i;
	if (deep == n) {
		result[n] = 0;
		puts(result);
		return;
	}
	for (i = n - 1; i >= 0; i--) {
		if (!used[i]) {
			used[i] = 1;
			result[deep] = num[i];
			recursive(deep + 1);
			used[i] = 0;
		}
	}
}

int main(void)
{
	int i;
	for (i = 0; i < 9; i++)
		num[i] = '1' + i;
	while (scanf("%d", &n) != EOF) {
		recursive(0);
	}
	return 0;
}
