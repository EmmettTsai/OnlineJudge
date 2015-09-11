#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1000001

int gcd(int a, int b)
{
	while ((a %= b) && (b %= a));
	return a == 0 ? b : a;
}

int main(void)
{
	int c, n, m, n_2, m_2, x, y, z, cx, cy, cz;
	int *ans1 = (int *)malloc(MAX * sizeof(int));
	int *ans2 = (int *)malloc(MAX * sizeof(int));
	int *min_used = (int *)malloc(MAX * sizeof(int));

	memset(ans1, 0, sizeof(ans1));
	memset(ans2, 0, sizeof(ans2));
	memset(min_used, 0, sizeof(min_used));

	for (n = 0; n < MAX; n++)
		min_used[n] = MAX;

	for (m = 1; m < 1000; m++)
	{
		for (n = m + 1; ; n += 2)
		{
			if (gcd(m, n) != 1)
				continue;

			m_2 = m * m;
			n_2 = n * n;
			z = m_2 + n_2;

			if (z >= MAX)
				break;

			x = n_2 - m_2;
			y = 2 * m * n;

			ans1[z]++;

			cx = x;
			cy = y;
			cz = z;
			while (cz < MAX)
			{
				if (cz < min_used[cx])
					min_used[cx] = cz;
				if (cz < min_used[cy])
					min_used[cy] = cz;
				if (cz < min_used[cz])
					min_used[cz] = cz;
				cx += x;
				cy += y;
				cz += z;
			}
		}
	}

	for (n = 1; n < MAX; n++)
	{
		ans1[n] += ans1[n - 1];
		ans2[n] += ans2[n - 1] + 1;
		if (min_used[n] != MAX)
			ans2[min_used[n]]--;
	}

	while (scanf("%d", &n) != EOF)
		printf("%d %d\n", ans1[n], ans2[n]);

	free(ans1);
	free(ans2);
	free(min_used);

	return 0;
}
