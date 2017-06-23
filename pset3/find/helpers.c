/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int ending = n-1;
    int beggining = 0;

    while (ending >= beggining)
    {
        int middle = (beggining + ending) / 2;
        if (values[middle] == value)
        {
           return true;
        }
        else if (values[middle] > value)
        {
            ending = middle - 1;
        }
        else
         {   beggining = middle + 1;
         }
    }
	

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    for(int i=0;i<n;i++)
    {
        for( int j=i;j<n;j++)
        {
            if(values[i]>values[j])
            {
                int temp=values[i];
                values[i]=values[j];
                values[j]=temp;
            }
        }
    }
    
}
