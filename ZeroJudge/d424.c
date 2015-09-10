#include <stdio.h>
#include <stdlib.h>

struct skyline
{
	int x;
	int h;
	struct skyline *next;
};

struct skyline* new(int x, int h, struct skyline *next)
{
	struct skyline *ptr = malloc(sizeof(struct skyline));
	ptr->x = x;
	ptr->h = h;
	ptr->next = next;
	return ptr;	
}

void delete_next(struct skyline *head)
{
	struct skyline *ptr = head->next;
	head->next = ptr->next;
	free(ptr);
}

int main(void)
{
	int L, H, R, old_h;
	struct skyline *ptr, *tmp, *head = new(0, 0, NULL);

	scanf("%d %d %d", &L, &H, &R);
	head->next = new(L, H, NULL);
	head->next->next = new(R, 0, NULL);

	while (scanf("%d %d %d", &L, &H, &R) != EOF)
	{
		if (L >= R || H <= 0)
			continue;
		for (ptr = head; ptr->next && ptr->next->x < L; ptr = ptr->next);
		if (ptr->next)
		{
			old_h = -1;
			if (ptr->next->x > L && ptr->h < H)
			{
				old_h = ptr->h;
				ptr->next = new(L, H, ptr->next);
				ptr = ptr->next;
			}
			while (ptr->next && ptr->next->x < R)
			{
				old_h = ptr->next->h;
				if (ptr->next->h <= H)
				{
					if (ptr->h == H)
						delete_next(ptr);
					else
					{
						ptr->next->h = H;
						ptr = ptr->next;
					}
				}
				else
					ptr = ptr->next;
			}
			if (ptr->next)
			{
				if (ptr->next->x == R)
				{
					if (ptr->h == H && ptr->next->h == H)
						delete_next(ptr);
				}
				else
				{
					if (old_h != -1 && old_h < H)
						ptr->next = new(R, old_h, ptr->next);
				}
			}
			else
			{
				if (ptr->x == R)
					ptr->h = 0;
				else
					ptr->next = new(R, 0, NULL);
			}			
		}
		else
		{
			ptr->next = new(L, H, NULL);
			ptr->next->next = new(R, 0, NULL);
		}
	}

	for (ptr = head->next; ptr->next; ptr = ptr->next)
		printf("%d %d ", ptr->x, ptr->h);
	printf("%d %d\n", ptr->x, ptr->h);

	while (head->next)
	{
		ptr = head->next;
		head->next = ptr->next;
		free(ptr);
	}
	free(head);

	return 0;
}
