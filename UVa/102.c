#include <stdio.h>

static int bin[3][3], total, order[3] = {-1, -1, -1};
static char bottle[4] = "";

void DFS(int index, int sum)
{
    int i;
    if (index == 3)
    {   
        if (total < sum)
        {   
            total = sum;
            for (i = 0; i < 3; i++)
                bottle[order[i]] = "BCG"[i];
        }   
        return;
    }   
    for (i = 0; i < 3; i++)
    {   
        if (order[i] == -1) 
        {   
            order[i] = index;
            DFS(index + 1, sum + bin[index][i]);
            order[i] = -1; 
        }   
    }   
}

int main(void)
{
    int i, j;
    while (scanf("%d %d %d %d %d %d %d %d %d",
        &bin[0][0], &bin[0][2], &bin[0][1],
        &bin[1][0], &bin[1][2], &bin[1][1],
        &bin[2][0], &bin[2][2], &bin[2][1]) != EOF)
    {   
        total = -1; 
        DFS(0, 0); 
        total = -total;
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                total += bin[i][j];
        printf("%s %d\n", bottle, total);
    }   
    return 0;
}
