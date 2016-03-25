#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, carry, tmp;
	char *init, *current;

	init = (char*) malloc(10000001);
	current = (char*) malloc(10000001);
	scanf("%s %s", init, current);

	carry = 1;
	for (i = 0; current[i] != 0; i++) {
		tmp = (current[i] == init[i] ? 0 : 1) + carry;
		carry = tmp > 1;
		current[i] = (tmp == 1 ? '1' : '0') == init[i] ? '0' : '1';
	}
	printf("%s\n", current);
	free(init);
	free(current);
	return 0;
}
