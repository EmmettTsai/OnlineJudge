#include <stdio.h>
#include <math.h>

double sigma(int arr[10000], int N) {
	int i;
	double avg = 0, s = 0;

	for (i = 0; i < N; i++)
		avg += arr[i];
	avg /= N;
	for (i = 0; i < N; i++)
		s += arr[i] * arr[i];
	return sqrt(s / N - avg * avg);
}

int main(void)
{
	
	int T, N, Q, i, j, k, arr[10000], a, b;
	double s;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		for (j = 0; j < N; j++)
			scanf("%d", &arr[j]);
		scanf("%d", &Q);
		s = sigma(arr, N);
		printf("%.2f\n", s);
		for (j = 0; j < Q; j++) {
			scanf("%d %d", &a, &b);
			printf("%.2f\n", s * (a < 0 ? -a : a));
		}
		putchar('\n');
	}
	return 0;
}
