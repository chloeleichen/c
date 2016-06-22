#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string cipher(string, string);
#define ALPHABET 26
static const int start[] = {(int)'a', (int)'A'};

int main(int argc, char* argv[])
{
    
    int len;
    string message;
    string k;

    if(argc != 2)
    {
        printf("wrong number of argument\n");
        return 1;
    }
    len = (int)strlen(argv[1]);

    // each char in second argument must be letter
    for (int i = 0; i <len; i ++ )
    {
        if(!isalpha(argv[1][i])){
            printf("second argument needs to be a string\n");
            // break out of the loop
            return 1;
        }
    }
    k = argv[1];
    //printf("your message:\n");
    message = GetString();
    printf("%s\n", cipher(message, k));
    return 0;
}

string cipher(string message, string key){
    int length = (int)strlen(message);
    int index =0;

    for(int i = 0; i < length; i ++)
    {
        int index_ascii = (int)message[i];
        int origin = index_ascii;
        int transformed = origin;
        int k_len = (int)strlen(key);
        int k;

        if(isalpha(message[i]))
        {
            int key_base = isupper(key[index%k_len]) ? start[1] : start[0];
            int base = isupper(message[i]) ? start[1] : start[0];

            if(index < k_len)
            {
                k = (int)key[index] - key_base;
            }
            else 
            {
                k = (int)key[index%(k_len)] - key_base;
            }
            index ++;
            transformed = (origin - base + k)%ALPHABET + base;
        }
        
        message[i] = (char)transformed;
    }
    return message;
}

