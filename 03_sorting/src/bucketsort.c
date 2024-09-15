#include "array_utility.h"
#include "quicksort.h"

void bucketsort(char a[], int l, int r, double lb, double ub, int k)
{
    double buckets[][]
    for(int j = 0; j<k; j++)
    {
        buckets.push_back(Array<T>());
    }

    // Put all elements into bucket
    for(int i = l; i <= r; i++)
    {
        int m = (k*(a[i]-lb)/(ub-lb));
        buckets[m].push_back(a[i]);
    }

    // Sort & concatenate bucket
    int i = l;
    for(int j = 0; j < k; j++)
    {
        // Sort bucket
        quicksort(buckets[j]);
        // Concatenate
        for(int m = 0; m < buckets[j].size(); m++)
        {
            a[i++] = buckets[j][m];
        }
    }
}