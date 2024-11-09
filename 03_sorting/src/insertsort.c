#include "insertsort.h"
#include "array_utility.h"

void insertsort(char a[], int l, int r)
{
    for (int i = l+1; i <= r; ++i)
    {
        for(int j = i; (j > l) && (a[j-1] > a[j]); j--)
        {
            array_swap(a, j-1, j);
        }
    }
}