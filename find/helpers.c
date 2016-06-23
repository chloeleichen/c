/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>


#include "helpers.h"

bool linearSearch(int value, int values[], int n);
void bubbleSort(int values[], int n);
void selectionSort(int values[], int n);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    return linearSearch(value, values, n);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    bubbleSort(values, n);
    return;
}

bool linearSearch (int value, int values[], int n)
{
    for(int i = 0; i < n; i ++){
        if(values[i] == value){
            return true;
        }
    }
    return false;
}

void bubbleSort(int values[], int n)
{
    int sorted = 1;
    for(int i = 0; i < n - 1; i ++){
        int value_current = values[i];
        int value_next = values[i + 1];
        if(value_current > value_next){
            values[i] = value_next;
            values[i + 1] = value_current;
            sorted = 0;
        }
    }
    if (sorted == 0) bubbleSort(values, n);
}

void selectionSort(int values[], int n)
{
    
}


