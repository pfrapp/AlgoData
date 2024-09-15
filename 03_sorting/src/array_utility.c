#include <stdio.h>
#include "array_utility.h"

void array_swap(char a[], int i, int j)
{
	char temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void array_print(char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", a[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
}