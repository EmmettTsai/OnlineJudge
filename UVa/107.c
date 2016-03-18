#include <stdio.h>
#include <math.h>

int main(void) {
	int height, cats, N, tmp, n;

	while (scanf("%d %d", &height, &cats), height != 0) {
		if (height == 1) {
			printf("0 1\n");
		} else {
			if ((height & 1) == 0) {
				for (tmp = height, n = 1; (tmp & 1) == 0; tmp >>= 1, n++);
				do {
					n--;
					N = (int) (pow((double)height, 1.0 / n) - 1 + 0.5);
				} while ((int)pow((double)N, n) != cats);
			} else {
				for (tmp = cats, n = 1; (tmp & 1) == 0 ; tmp >>= 1, n++);
				do {
					n--;
					N = (int) (pow((double)cats, 1.0 / n) + 0.5);
				} while ((int)pow((double)(N + 1), n) != height);
			}
			printf("%d %d\n", N == 1 ? n : (cats - 1) / (N - 1), height * (N + 1) - cats * N);
		}
	}
	return 0;
}
