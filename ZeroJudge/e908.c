#include <stdio.h>
#include <string.h>

int main(void) {
    int n, i;
    char* week[7] = { "Sunday" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday" };
    char buf[10];
    scanf("%s\n%d", buf, &n);
    for (i = 0; i < 7; i++)
        if (strcmp(buf, week[i]) == 0)
            break;
    printf("%s", week[(i + (n % 7)) % 7]);
    return 0;
}