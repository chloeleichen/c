#include <cs50.h>
#include <stdio.h>
#include <math.h>
/*
  Question: http://cdn.cs50.net/2016/x/psets/1/pset1/pset1.html#time_for_change
  Check: check50 2015.fall.pset1.greedy greedy.c
 */

static const int coinsAvailable[4] = {25, 10, 5, 1};

int getCoins(int);
int main(){
    float input;
    int cents;
    int nCoins;

    do
    {
        printf("How much do I owe you ?\n");
        input = GetFloat();
    }
    while (input < 0);

    input = (float)round(input*100);

    //explicit type casting
    cents = (int)input;

    nCoins = getCoins(cents);
    printf("%d\n",nCoins);
    return 0;
}

int getCoins(int cents){
    int n = 0;
    for(int i = 0; i < 4; i ++){
        while (cents >= coinsAvailable[i])
        {
            cents -= coinsAvailable[i];
            // printf("give you: %d\n",coinsAvailable[i]);
            n ++;
        };
    }
    return n;
}
