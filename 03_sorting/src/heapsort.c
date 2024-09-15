#include "heapsort.h"
#include "array_utility.h"

void downheap(char a[], int l, int q, int r) {
    while (1)
    {
        int i = l + 2*(q-l) + 1;
        if (i > r) return;
        if ((i < r) && (a[i + 1] > a[i])) i++;
        if (a[i] <= a[q]) return;
        array_swap(a, q, i);
        q = i;
    }
}

void buildheap(char a[], int l, int r) {
    for (int i = (r-l-1) / 2; i >= 0; --i) {
        downheap(a, l, l+i, r);
    }
}

void heapsort(char a[], int l, int r) {
    buildheap(a, l, r);
    for (int i = r; i>l; --i) {
        array_swap(a, l, i);
        downheap(a, l, l, i-1);
    }
}