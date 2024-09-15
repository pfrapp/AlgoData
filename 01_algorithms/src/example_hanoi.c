#include <stdio.h>
#include "hanoi.h"

int main()
{
    // Reset counter
    counter = 0;

    // Solve problem
    hanoi(3, 'A', 'B', 'C');
}