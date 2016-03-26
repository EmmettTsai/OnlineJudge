#include <stdio.h>

int main(void) {
	int i = 0, d1, m1, y1, d2, m2, y2, age;

	scanf("%*d");
	while (scanf("%d/%d/%d %d/%d/%d", &d1, &m1, &y1, &d2, &m2, &y2) != EOF) {
		age = y1 - y2 - (m1 < m2 || (m1 == m2 && d1 < d2));
		if (age < 0)
			printf("Case #%d: Invalid birth date\n", ++i);
		else if (age > 130)
			printf("Case #%d: Check birth date\n", ++i);
		else
			printf("Case #%d: %d\n", ++i, age);
	}

	return 0;
}
