#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
  problem: http://cdn.cs50.net/2016/x/psets/2/pset2/pset2.html#hail_caesar
  check50 2015.fall.pset2.caesar caesar.c
 */

#define ALPHABET 26
string encrypt(string, int);
static const int start[] = {(int)'a', (int)'A'};

int main(int argc, char* argv[] )
{
    int k;
    char c;
    string message;

    if(argc != 2)
    {
        printf("wrong number of argument, exist\n");
        return 1;
    }
    if ((sscanf(argv[1], "%d %c", &k, &c) != 1) || k < 0)
    {
        printf("argument has to be a possitive interger, exist\n");
        return 1;
    }

    message = GetString();
    printf("%s\n",encrypt(message, k));
    return 0;
}

string encrypt(string message, int k){
    int length = (int)strlen(message);
    for(int i = 0; i < length; i ++)
    {
        int index_ascii = (int)message[i];
        int origin = index_ascii;
        int transformed = origin;

        if(isalpha(message[i]))
        {
            int base = isupper(message[i]) ? start[1] : start[0];
            transformed = (origin - base + k)%ALPHABET + base;
        }
        
        message[i] = (char)transformed;
    }
    
    return message;
}




