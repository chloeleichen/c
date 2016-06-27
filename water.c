#include <cs50.h>
#include <stdio.h>

int main(){
    printf("minutes:");
    int n = GetInt();
    printf("bottles: %d\n", n * 192 /16);
    return 0;
}

