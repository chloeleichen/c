/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
// #define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // expects one or two command-line arguments, if no commandline 
    // argument is given, exit 1
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // The number of numbers generated = the first commandline argument
    int n = atoi(argv[1]);

    // If the number of argument is 3, use the second argument in srand48
    // function to initialise the entry points for the random number 
    // generation
    // if the second command line argument is not given, use the current 
    // time for srand() function
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // create n lines of return non-negative, double-precision, floating-point 
    // values, uniformly distributed over the interval [0.0 , 1.0].
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
