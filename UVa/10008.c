#include <stdio.h>

int main(void) {
	int ch[26] = {0}, i, j;
	char CH[26], buf[1000], *ptr;
	scanf("%*d\n");
	while (gets(buf)) {
		for (ptr = buf; *ptr; ptr++) {
			if (*ptr >= 'A' && *ptr <= 'Z')
				ch[*ptr - 'A']++;
			else if (*ptr >= 'a' && *ptr <= 'z')
				ch[*ptr - 'a']++;
		}
	}
	for (i = 0; i < 26; i++)
		CH[i] = 'A' + i;
	for (i = 0; i < 25; i++) {
		for (j = i + 1; j < 26; j++) {
			if (ch[j] > ch[i]) {
				ch[i] ^= ch[j] ^= ch[i] ^= ch[j];
				CH[i] ^= CH[j] ^= CH[i] ^= CH[j];
			} else if (ch[j] == ch[i] && CH[j] < CH[i])
				CH[i] ^= CH[j] ^= CH[i] ^= CH[j];
		}
	}
	for (i = 0; i < 26 && ch[i] != 0; i++)
		printf("%c %d\n", CH[i], ch[i]);

	return 0;
}
