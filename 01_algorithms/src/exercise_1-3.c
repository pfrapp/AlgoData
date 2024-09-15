#include <stdio.h>
#include <time.h>
#include "guessing_game.h"

#define NUM_REPETITIONS		(1000000)

int main()
{
	int min_number, max_number;


	clock_t start_clock, end_clock;

	// Beispiel Zeitmessung
	start_clock = clock();
	for (int i = 0; i < NUM_REPETITIONS; i++)
	{
		// Hier steht der Code, dessen Laufzeit gemessen werden soll
	}
	end_clock = clock();
	double time = 1.0 * (end_clock - start_clock) / CLOCKS_PER_SEC;

	// TODO: Übung 1.3 (1)

	// TODO: Übung 1.3 (2)
}