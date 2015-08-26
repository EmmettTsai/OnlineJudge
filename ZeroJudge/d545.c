#include <stdio.h>

int main(void)
{
    int N, M, i, j;
    char card[52][2];

    scanf("%d\n", &N);
    for (i = 0; i < N; i++)
        scanf("%c %d ", &card[i][0], &card[i][1]);
    scanf("%d", &M);
    --M;
    for (i = 0; i <= M; i++)
    {   
        for (j = i + 1; j < N; j++)
        {   
            if (card[i][1] < card[j][1])
            {   
                card[i][0] ^= card[j][0] ^= card[i][0] ^= card[j][0];
                card[i][1] ^= card[j][1] ^= card[i][1] ^= card[j][1];
            }   
            else if (card[i][1] == card[j][1] && card[i][0] < card[j][0])
            {   
                card[i][0] ^= card[j][0] ^= card[i][0] ^= card[j][0];
            }   
        }   
    }   
    printf("%c %d\n", card[M][0], card[M][1]);

    return 0;
}
