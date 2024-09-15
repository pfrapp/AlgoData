#include "insertsort.h"
#include "array_utility.h"

void selectsort(char a[], int l, int r)
{
    for (int i = l; i < r; i++)
    {
        int q = i;
        for (int j = i + 1; j <= r; j++)
        {
            if (a[j] < a[q]) q = j;
        }
        array_swap(a, i, q);
    }
}
