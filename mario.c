#include <cs50.h>
#include <stdio.h>
/*
super mario ladders
   ##
  ###
 ####
#####
*/

int main()
{
    int height = 8;
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




