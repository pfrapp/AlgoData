#include "merge_sort.h"

void merge(char a[], char b[], int l, int q, int r)
{
    int i = l;
    int j = q + 1;
    for (int k = l; k <= r; k++)
    {
        if (i <= q && j <= r)
        {
            if (a[i] <= a[j])
            {
                b[k] = a[i];
                i++;
            }
            else
            {
                b[k] = a[j];
                j++;
            }
        }
        else if (i <= q)
        {
            b[k] = a[i];
            i++;
        }
        else if (j <= r)
        {
            b[k] = a[j];
            j++;
        }
    }

    // Copy back to original array
    for (int k = l; k <= r; k++)
    {
        a[k] = b[k];
    }
}

void merge_sort(char a[], char b[], int l, int r)
{
    if (l < r) {
        int q = (l + r) / 2;
        merge_sort(a, b, l, q);
        merge_sort(a, b, q + 1, r);
        merge(a, b, l, q, r);
    }
}