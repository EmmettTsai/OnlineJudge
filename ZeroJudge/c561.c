#include <stdio.h>

int main(void) {
    char buf1[7], buf2[7], *curr, *next, *tmp;
    int curr_len, next_len, i;
    curr = buf1;
    next = buf2;
    scanf("%*d\n%s", curr);
    curr_len = strlen(curr);
    while (scanf("%s", next) != EOF) {
        next_len = strlen(next);
        if (next_len > curr_len) {
            tmp = curr;
            curr = next;
            next = tmp;
            curr_len = next_len;
        } else if (next_len == curr_len) {
            for (i = curr_len - 1; i >= 0; i--) {
                if (next[i] < curr[i])
                    break;
                if (next[i] > curr[i]) {
                    tmp = curr;
                    curr = next;
                    next = tmp;
                    curr_len = next_len;
                    break;
                }
            }
        }
    }
    for (i = 0; i < curr_len; i++)
        next[i] = curr[curr_len - i - 1];
    next[curr_len] = 0;
    puts(next);
    return 0;
}