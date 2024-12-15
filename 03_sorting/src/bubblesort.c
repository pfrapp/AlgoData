#include <stdbool.h>
#include "bubblesort.h"
#include "array_utility.h"

void bubblesort(char a[], int l, int r)
{
    for (int i = r; i > l; i--)
    {
        bool swapped = false;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                array_swap(a, j, j + 1);
                swapped = true;
            }
        }
        if (!swapped) return;
    }
}