#include <stdio.h>

int main(void) {
    int a, b;
    char ch;
    while (scanf("%d %c %d", &a, &ch, &b) != EOF) {
        switch(ch) {
            case '+': a += b; break;
            case '-': a -= b; break;
            case '*': a *= b; break;
            case '/': a /= b; break;
        }
        printf("%d\n", a);
    }
    return 0;
}