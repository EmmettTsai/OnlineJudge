#include <stdio.h>
#include <stdlib.h>

struct box
{
	int no;
	int element[10];
} boxes[30];

static int n;

int int_order(const void* a, const void *b)
{
	return *(int*)a - *(int*)b;
} 

int box_order(const void* a, const void *b)
{
    int i;
    for (i = 0; i < n && ((struct box*)a)->element[i] == ((struct box*)b)->element[i]; i++);
    return i == n ? 0 : ((struct box*)a)->element[i] - ((struct box*)b)->element[i];
}

int nested(struct box *a, struct box *b)
{
	int i;
	for (i = 0; i < n; i++)
		if (a->element[i] >= b->element[i])
			return 0;
	return 1;
}

int main(void)
{
	int len[30], next[30], k, i, j;
	while (scanf("%d %d", &k, &n) != EOF)
	{
		for (i = 0; i < k; i++)
		{
			for (j = 0; j < n; j++)
				scanf("%d", &boxes[i].element[j]);
			qsort(boxes[i].element, n, sizeof(int), int_order);
			boxes[i].no = i + 1;
			len[i] = 1;
			next[i] = -1;
		}
		qsort(boxes, k, sizeof(struct box), box_order);

		for (i = k - 1; i >= 0 ; i--)
			for (j = 0; j < i ; j++)
				if (nested(&boxes[j], &boxes[i]))
					if (len[i] + 1 > len[j])
					{
						len[j] = len[i] + 1;
						next[j] = i;
					}
		i = 0;
		for (j = 1; j < k; j++)
			if (len[j] > len[i])
				i = j;
		printf("%d\n", len[i]);
		for ( ; i != -1; i = next[i])
			printf("%d ", boxes[i].no);
		putchar('\n');
	}

	return 0;
}
