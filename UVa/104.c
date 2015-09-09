#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, j, k, m, n, path[20][20][22];
	double transaction[20][20][22];
	int debug = 1;

start:
	while (scanf("%d", &n) != EOF)
	{
		memset(transaction, 0, sizeof(transaction));
		memset(path, 0, sizeof(path));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i != j)
				{
					scanf("%lf", &transaction[i][j][1]);
					path[i][j][1] = j;
				}
			}
		}

		for (m = 1; m < n; m++)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					for (k = 0; k < n; k++)
					{
						if (transaction[i][k][1] * transaction[k][j][m] > transaction[i][j][m + 1])
						{
							transaction[i][j][m + 1] = transaction[i][k][1] * transaction[k][j][m];
							path[i][j][m + 1] = k;
						}
					}
				}
			}
			for (i = 0; i < n; i++)
			{
				if (transaction[i][i][m + 1] > 1.01)
				{
					for (j = m + 1, k = i; j > 0; j--)
					{
						printf("%d ", k + 1);
						k = path[k][i][j];
					}
					printf("%d\n", i + 1);
					goto start;
				}
			}
		}
		printf("no arbitrage sequence exists\n");
	}
	
	return 0;
}
