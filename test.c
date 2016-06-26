#include <cs50.h>
#include <stdio.h>

int check(void);
static int board[3][3] = {{1, 10, 3}, {4, 5, 6}, {7, 8, 0}};

int main()
{
    printf("%d\n",check());
    return 1;
    
}

int check()
{
    int d = 3;
    if(board[d-1][d-1] != 0) return 0;

    for(int i = 0; i < d; i ++)
    {
        if(i < d-1)
        {
            if(board[i][0] > board[i+1][0]) return 0;
        }
        for(int j = 0; j < d -2; j ++)
        {
            if((i!= d-1) && (j != d-1) && (board[i][j] > board[i][j+1]))
            {
                return 0;
            }
        }
    }

    return 1;
}





