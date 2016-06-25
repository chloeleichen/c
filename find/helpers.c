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

bool binarySearch(int value, int values[], int min, int max);
bool linearSearch(int value, int values[], int n);
void bubbleSort(int values[], int n);
void insertionSort(int values[], int n);
void selectionSort(int values[], int n);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    return binarySearch(value, values, 0, n);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    insertionSort(values, n);
    for(int i =0; i < n; i ++)
    {
        printf("%d\n",values[i]);
    }
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
    if(n < 2){
        return;
    }
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
    if(n < 2) return;
    for (int i = 1; i < n; i ++)
    {
        int min_index = i;
        int initial_min = values[i];
        for (int j = i; j < n; j ++)
        {
            if(values[j] < values[min_index]){
                min_index = j;
            }
        }
        if( i != min_index)
        {
            values[i] = values[min_index];
            values[min_index] = initial_min;
        }
    }
}


void insertionSort(int values[], int n)
{
    if(n < 2) return;
    int current;
    int sorted_index;

    for (int i = 1; i < n; i ++)
    {
        current = values[i];
        sorted_index = i;
        while(sorted_index > 0 && values[sorted_index - 1] > current)
        {
            values[sorted_index] = values[sorted_index - 1];
            sorted_index = sorted_index - 1;
            values[sorted_index] = current;
        }
    }
}

bool binarySearch(int value, int values[], int min, int max)
{
    if (min > max)
    {
         return false;
    } 
    else
    {
        int center = min + (max - min) /2;
        if(values[center] > value)
        {
            return binarySearch(value, values, min, center - 1);
        }
        else if(values[center] < value)
        {
            return binarySearch(value, values, center + 1, max);
        }
        else 
        {
            return true;
        }
    }
}


