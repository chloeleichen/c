#include <stdio.h>
#include <stdlib.h>

enum { ARR_LEN = 100 };

int main()
{
    // char constant
    int c = 0;

    c = getchar();
    if( c != EOF && c > '0' && c < '6')
    {
        printf("entered %d\n",c);
        printf("%d\n", '0');
        printf("%d\n", '6');
    }

    return 0;
}




