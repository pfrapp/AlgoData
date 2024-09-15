#include <stdio.h>
#include "hanoi.h"

void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        printf("%i: Move from %c to %c\n", ++counter, A, C);
        return;
    }
    hanoi(n - 1, A, C, B);
    hanoi(1, A, B, C);
    hanoi(n - 1, B, A, C);
}