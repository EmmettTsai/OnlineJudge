#include <stdio.h>

int main(void) {
    char buf[11];
    int kill = 0, die = 0, assist = 0, combo = 0;
    scanf("%d");
    while (scanf("%s", buf) != EOF) {
        if (buf[0] == 'D') {
            if (combo < 3)
                printf("You have been slained.\n");
            else
                printf("SHUTDOWN.\n");
            combo = 0;
            die++;
        }
        else if (buf[4] == 'K') {
            switch (++combo) {
                case 1:
                case 2:
                    printf("You have slain an enemie.\n");
                    break;
                case 3:
                    printf("KILLING SPREE!\n");
                    break;
                case 4:
                    printf("RAMPAGE~\n");
                    break;
                case 5:
                    printf("UNSTOPPABLE!\n");
                    break;
                case 6:
                    printf("DOMINATING!\n");
                    break;
                case 7:
                    printf("GUALIKE!\n");
                    break;
                default:
                    printf("LEGENDARY!\n");
                    break;
            }
            kill++;
        }
        else
            assist++;
    }
    printf("%d/%d/%d\n", kill, die, assist);
    return 0;
}