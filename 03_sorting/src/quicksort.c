#include "quicksort.h"
#include "array_utility.h"

int partition(char a[], int l, int r)
{
    char p = a[(l + r) / 2]; // pivot
    int i = l - 1, j = r + 1;
    for (;;) {
        do { i++; } while (a[i] < p);
        do { j--; } while (a[j] > p);
        if (i < j) array_swap(a, i, j);
        else return j;
    }
}

void quicksort(char a[], int l, int r)
{
    if (l < r) {
        int q = partition(a, l, r);
        quicksort(a, l, q);
        quicksort(a, q + 1, r);
    }
}