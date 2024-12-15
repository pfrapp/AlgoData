#include "countingsort.h"

void countingsort(char a[], char b[], int c[], int l, int r, int k, int (*key)(char))
{
    // Initialize with zeros
    for (int i = 0; i < k; i++) 
        c[k] = 0;

    // Count occurences
    for (int j = l; j <= r; j++) 
        c[key(a[j])]++;

    // Compute address/position
    for (int i = 1; i < k; i++) 
        c[i] += c[i - 1];

    // Insert at correct position
    for (int j = r; j >= l; j--)
    {
        c[key(a[j])]--;
        b[c[key(a[j])] + l] = a[j];
    }

    // Copy result back to original array
    for (int j = l; j <= r; j++)
        a[j] = b[j];
}