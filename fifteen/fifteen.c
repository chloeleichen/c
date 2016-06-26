/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;
int blank[2];

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
int* findTile(int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(50000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(200000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    for(int i = 0; i < d; i ++)
    {
        for(int j = 0; j < d; j ++)
        {
            board[i][j]= (d -1 - j) + d*(d - i - 1);
        }
    }
    // swap 1 and 2 if odd number of tiles 
    // means if d is even number 
    if(d%2 == 0)
    {
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for(int i = 0; i < d; i ++)
    {
        for(int j = 0; j < d; j ++)
        {
            if (board[i][j] != 0)
            {
                printf("%2d",board[i][j]);
            }
            else 
            {
                blank[0] = i;
                blank[1] = j;
                printf(" _ ");
            }
            
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    if(!findTile(tile)){
        return false;
    }
    else
    {
        int* active_tile = findTile(tile);
        if((abs(active_tile[0] - blank[0]) == 1 && abs(active_tile[1] - blank[1]) == 0)
        || (abs(active_tile[0] - blank[0]) == 0 && abs(active_tile[1] - blank[1]) == 1))
        {
            printf("move\n");
            //swap current active with empty
            board[active_tile[0]][active_tile[1]] = 0;
            board[blank[0]][blank[1]] = tile;
            blank[0] = active_tile[0];
            blank[1] = active_tile[1];

            //redraw
            draw();
            return true;
        }
        // printf("%d, %d\n", active_tile[0], active_tile[1]);
        return false;
    }
    
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    for(int i = 0; i < d -1; i ++)
    {
        for(int j = 0; j < d-1; j ++)
        {
            if(board[i][j] > board[i][j+1])
            {
                return false;
            }
        }
        if(board[i][0] > board[i + 1][0])
        {
            return false;
        }
    }
    return true;
}

/*
 Given value of tile, return position of this tile on the board
 */

int* findTile(int tile)
{
    if (tile >= d*d || tile <=0)
    {
        return false;
    }

    static int cordinates[2];

    for(int i = 0; i < d; i ++)
    {
        for(int j = 0; j < d; j ++)
        {
            if(board[i][j] == tile)
            {
                cordinates[0]= i;
                cordinates[1]=j;
                break;
            }
        }
    }
    return cordinates;
}
