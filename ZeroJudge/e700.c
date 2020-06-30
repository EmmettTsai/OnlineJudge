#include <stdio.h>

int main(void) {
    int m, d;
    while (scanf("%d/%d", &m, &d) != EOF) {
        if ((m == 1 && d >= 21) || (m == 2 && d <= 19))
            printf("水瓶座\n");
        else if ((m == 2 && d >= 20) || (m == 3 && d <= 20))
            printf("雙魚座\n");
        else if ((m == 3 && d >= 21) || (m == 4 && d <= 20))
            printf("牡羊座\n");
        else if ((m == 4 && d >= 21) || (m == 5 && d <= 21))
            printf("金牛座\n");
        else if ((m == 5 && d >= 22) || (m == 6 && d <= 21))
            printf("雙子座\n");
        else if ((m == 6 && d >= 22) || (m == 7 && d <= 22))
            printf("巨蟹座\n");
        else if ((m == 7 && d >= 23) || (m == 8 && d <= 21))
            printf("獅子座\n");
        else if ((m == 8 && d >= 22) || (m == 9 && d <= 23))
            printf("處女座\n");
        else if ((m == 9 && d >= 24) || (m == 10 && d <= 23))
            printf("天秤座\n");
        else if ((m == 10 && d >= 24) || (m == 11 && d <= 22))
            printf("天蠍座\n");
        else if ((m == 11 && d >= 23) || (m == 12 && d <= 22))
            printf("射手座\n");
        else if ((m == 12 && d >= 23) || (m == 1 && d <= 20))
            printf("摩羯座\n");
    }
    return 0;
}