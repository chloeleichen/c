#include <cs50.h>
#include <stdio.h>
/*
Question: http://cdn.cs50.net/2016/x/psets/1/pset1/pset1.html#itsa_mario
*/

void makeLadders(int);
int main()
{
    int n;
    do
    {
        printf("Please input an integer value between 0 and 23: ");
        n = GetInt();
    }
    while (n < 0 || n > 23);

    makeLadders(n);
    return 0;
}

void makeLadders(int n)
{
    int height = n;
    int column = height + 1;

    for(int i = 0; i < height; i ++)
    {
        for (int j = 0; j < column; j ++)
        {
            if(j < column - i - 2){
                printf("%s", " ");
            }
            else if(j == column - 1){
                printf("%s\n", "#");
            }
            else{
                printf("%s", "#");
            }

        }
    }
}
