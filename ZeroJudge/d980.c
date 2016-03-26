#include <stdio.h>

int main(void) {
	int i = 0;
	long a, b, c;

	scanf("%*d");
	while (scanf("%ld %ld %ld", &a, &b, &c) != EOF) {
		if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a) {
			if (a == b && b == c)
				printf("Case %d: Equilateral\n", ++i);
			else if (a == b || a == c || b == c)
				printf("Case %d: Isosceles\n", ++i);
			else
				printf("Case %d: Scalene\n", ++i);
		} else
			printf("Case %d: Invalid\n", ++i);
	}

	return 0;
}
