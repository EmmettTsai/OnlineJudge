#include <stdio.h>

int main(void) {
    char buf[100];
    scanf("%s", buf);
    printf("%s little", buf);
    while (scanf("%s", &buf) != EOF)
        printf(", %s little", buf);
    puts(" Indians");
    return 0;
}