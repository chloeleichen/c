#include <cs50.h>
#include <stdio.h>
/*
super mario ladders
   ##
  ###
 ####
#####
*/

void makeLadders(int);
int main()
{
    int n;
    do
    {
        printf("Please input an integer value between 1 and 30: ");
        scanf("%d", &n);
    }
    while (n < 1 || n > 30);

    makeLadders(n);
    return 0;
}

void makeLadders(int n)
{
    int height = n;
    int column = height + 1;
    int test = 0;

    for(int i = 0; i < height; i ++)
    {
        test ++;
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
    printf("the height of the ladder is %d\n", test);
}





