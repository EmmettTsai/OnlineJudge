#include <stdio.h>

#define QUEUE_SIZE 100000

int main(void) {
    int k, queue[QUEUE_SIZE], head = 0, tail = 0;
    scanf("%*d");
    while (scanf("%d", &k) != EOF) {
        switch (k) {
            case 1:
                scanf("%d", &queue[tail]);
                if (++tail == QUEUE_SIZE)
                    tail = 0;
                break;
            case 2:
                if (head != tail)
                    printf("%d\n", queue[head]);
                else
                    puts("-1");
                break;
            default:
                if (head != tail)
                {
                    if (++head == QUEUE_SIZE)
                        head = 0;
                }
        }
    }
    return 0;
}