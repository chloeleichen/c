#include <stdio.h>
#include <math.h>
/*
  given the change required 
  print the list amount of coin needed
 */

int coinsAvailable[4] = {25, 10, 5, 1};

int getCoins(int);
int main(){
    float input;
    int cents;
    int dollars;
    int n;

    printf("How much do I owe you ?\n");
    input = GetFloat();

    input = round(input*100);
    cents = input;
    cents = cents%100;

    n = getCoins(cents);
    printf("%d\n",n);
    return 0;
}

int getCoins(int cents){
    int n = 0;
    printf("cents: %d\n", cents);
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


