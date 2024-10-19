#include <stdio.h>
#include <time.h>
#include "guessing_game.h"

#define NUM_REPETITIONS		(1000000)

int main()
{
	int min_number, max_number;

	min_number = 0;
	max_number = 100;  // <-- Problemgroesse
	secret_number = 3;

	clock_t start_clock, end_clock;

	// Beispiel Zeitmessung
	start_clock = clock();
	for (int i = 0; i < NUM_REPETITIONS; i++)
	{
		find_number_dc(min_number, max_number);
	}
	end_clock = clock();
	double time = 1.0 * (end_clock - start_clock) / CLOCKS_PER_SEC;

	// Uebung 1.3 (1)
	printf("Took %f seconds\n", time);

	// Uebung 1.3 (2)
}

// Uebung 1.3 (1)

// min_number = 0, max_number = 100, secret_number = 80
// Brute force:        0.246076
// Divide-and-conquer: 0.032466

// min_number = 0, max_number = 200, secret_number = 160
// Brute force:        0.444393
// Divide-and-conquer: 0.045740

// min_number = 0, max_number = 400, secret_number = 320
// Brute force:        0.867374
// Divide-and-conquer: 0.037223



// Uebung 1.3 (2)
// Brute force
//   secret_number = 3:  0.023242
//   secret_number = 13: 0.060090
//   secret_number = 37: 0.127667
//   secret_number = 73: 0.212251
// Divide-and-conquer
//   secret_number = 3:  0.022671
//   secret_number = 13: 0.026296
//   secret_number = 37: 0.019442
//   secret_number = 73: 0.030013
