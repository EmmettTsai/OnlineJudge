#include <stdio.h>

int main(void)
{
	int n, arr[4] = {0};
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &arr[0]);
		arr[arr[0]]++;
	}
	while (arr[1]--)
		printf("1 ");
	while (arr[2]--)
		printf("2 ");
	while (arr[3]--)
		printf("3 ");
	return 0;
}
