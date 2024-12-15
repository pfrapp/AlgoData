#include <stdio.h>
#include <stdlib.h>
#include "countingsort.h"

#define N   (20)

int char_key(char v)
{
    return (int) v;
}

int main()
{
    char data[] = {};
    char* temp = malloc(sizeof(data));
    char buckets[256];

    // Sort and print
    countingsort(data, temp, buckets, 0, , 256, char_key);
}