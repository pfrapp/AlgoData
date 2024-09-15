#include <stdio.h>
#include "factorial.h"

int main()
{
	int n = 8;

	printf("Recursive: %i\n", factr(n));
	printf("Iterative: %i\n", facti(n));
}