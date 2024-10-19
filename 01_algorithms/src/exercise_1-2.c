#include <stdio.h>
#include "guessing_game.h"

int main()
{
	int min_number = 0;
	int max_number = 20;
	secret_number = 13;

	printf("Brute-force solution:                  %i\n", find_number_bf(min_number, max_number));
	printf("Divide-and-conquer solution iterative: %i\n", find_number_dc(min_number, max_number));
	printf("Divide-and-conquer solution recursive: %i\n", find_number_dcr(min_number, max_number));
}