#include <stdio.h>

int main(void)
{
	char command[2][5];
	int n, a, b, i, j, k, blocks[25][25], top[25], pos[25];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		pos[i] = blocks[i][0] = i;
		top[i] = 0;
	}

	while (scanf("%s %d %s %d", command[0], &a, command[1], &b) == 4)
	{
		if (a == b || pos[a] == pos[b])
			continue;

		if (command[1][1] == 'n') /* onto */
			while (blocks[pos[b]][top[pos[b]]] != b)
			{
				i = blocks[pos[b]][top[pos[b]]--];
				pos[i] = i;
				top[i] = 0;
			}

		if (command[0][0] == 'm') /* move */
		{
			while (blocks[pos[a]][top[pos[a]]] != a)
			{
				i = blocks[pos[a]][top[pos[a]]--];
				pos[i] = i;
				top[i] = 0;
			}

			blocks[pos[b]][++top[pos[b]]] = a;
			top[pos[a]]--;
			pos[a] = pos[b];
		}
		else /* pile */
		{
			i = pos[a];
			for (j = 0; blocks[i][j] != a; j++);
			for (k = j; k <= top[i]; k++)
			{
				blocks[pos[b]][++top[pos[b]]] = blocks[i][k];
				pos[blocks[i][k]] = pos[b];
			}
			top[i] = j - 1;
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d:", i);
		for (j = 0; j <= top[i]; j++)
			printf(" %d", blocks[i][j]);
		putchar('\n');
	}
	return 0;
}
