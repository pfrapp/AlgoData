#include "listsearch.h"
#include <stdio.h>

/** Linear Search **/
int linear_search(char a[], int l, int r, char value)
{
    for(int i = l; i <= r; i++)
    {
        if(a[i] == value) 
        {
            return i;
        }
    }
    return -1;
}


/** Binary Search **/
int binary_search(char a[], int l, int r, char value)
{
    while(l <= r)
    {
        int i = (l+r)/2;
        printf("Grenze %i\n", i);
        if(a[i] == value)
        {
            return i;
        }
        else if(a[i] < value)
        {
            l = i+1;
        }
        else if(value < a[i])
        {
            r = i-1;
        }
    }
    return -1;
}


/** Interpolation Search **/
int interpolation_search(char a[], int l, int r, char value)
{
    if(value >= a[l] && value <= a[r])
    {
        while(l < r)
        {
            int i = l + (r-l)/(a[r]-a[l])*(value - a[l]);
            printf("Grenze %i\n", i);
            if(a[i] == value)
            {
                return i;
            }
            else if(a[i] < value)
            {
                l = i+1;
            }
            else if(value < a[i])
            {
                r = i-1;
            }
        }
        if((l == r) && (a[l] == value)) return l;
    }
    return -1;
}


/** Exponential Search **/
int exponential_search(char a[], int l, int r, char value)
{
    int step_size = 1;
    int i = 0;
    while(i + step_size <= r)
    {
        if(value < a[i + step_size]) 
        {
            break;
        }
        else
        {
            i += step_size; // shift block start
            step_size *= 2; // double block size
        }
    }
    // Limit block end to r
    int j = i + step_size;
    if(j > r)
    {
        j = r;
    }
    // Run binary search on block
    return binary_search(a, i, j, value);
}