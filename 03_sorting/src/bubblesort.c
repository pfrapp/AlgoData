#include <stdbool.h>
#include "bubblesort.h"
#include "array_utility.h"

void bubblesort(char a[], int l, int r)
{
    // TODO: Übung 3.1 (4)
    for (int i = r; i > l; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                array_swap(a, j, j + 1);
            }
        }
    }
}