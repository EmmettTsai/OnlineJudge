#include <stdio.h>

int main(void) {
	int i, j, carry;
	char a[11], b[11];
	while (1) {
		scanf("%d %d", &i, &j);
		if (i == 0 && j == 0)
			break;
		sprintf(a, "%0*d", 9, i);
		sprintf(b, "%0*d", 9, j);
		carry = 0;
		for (i = 8, j = 0; i >= 0; i--) {
			j = (a[i] + b[i] + j >= '5' + '5');
			carry += j;
		}
		if (carry) {
			printf("%d carry operation%s.\n", carry, carry == 1 ? "" : "s");
		} else
			printf("No carry operation.\n");
	}
	return 0;
}
