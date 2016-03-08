#include <stdio.h>

long long gcd(long long a, long long b) {
	while ((a %= b) && (b %= a));
	return a + b;
}

long long recursive(long long a, long long b) {
	if (a > b)
		return recursive(a - b, b) * 2;
	if (a < b)
		return recursive(b, a) + 1;
	return 1;
}

int main(void)
{
	long long a, b, c;
	while (scanf("%lld %lld", &a, &b) != EOF) {
		c = gcd(a, b);
		a /= c;
		b /= c;
		printf("%lld\n", recursive(a, b));
	}
	return 0;
}
