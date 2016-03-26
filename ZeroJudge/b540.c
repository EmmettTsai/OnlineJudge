#include <stdio.h>

int main(void) {
	int a, b, c, d, e, f, p, q, r;

	while (scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f) != EOF) {
		p = (a < c ? a : c);
		q = (a < c ? c : a) - p;
		r = (d < f ? d : f);
		printf("%d\n", (2 * b + p) * p + (2 * (b + p)) * q + (2 * e + r) * r);
	}
	return 0;
}
