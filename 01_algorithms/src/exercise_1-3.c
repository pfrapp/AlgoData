#include <stdio.h>
#include <time.h>
#include "guessing_game.h"

#define NUM_REPETITIONS		(1000000)

double measure_time(int min_number, int max_number, int (*fcn)(int,int))
{
	clock_t start_clock, end_clock;

	start_clock = clock();
	for (int i = 0; i < NUM_REPETITIONS; i++)
	{
		fcn(min_number, max_number);
	}
	end_clock = clock();

	return 1.0 * (end_clock - start_clock) / CLOCKS_PER_SEC;
}

int main()
{
	int min_number, max_number;

	// Übung 1.3 (1)
	min_number = 0;
	int max_numbers[] = { 100, 200, 400 };
	printf("EXERCISE 1.3 (2)\n");
	printf("  Max. number | Brute-force | Divide-and-conquer\n");
	for (int i = 0; i < 3; i++)
	{
		max_number = max_numbers[i];
		secret_number = 0.8 * max_number;
		double time_bf = measure_time(min_number, max_number, find_number_bf);
		double time_dc = measure_time(min_number, max_number, find_number_dc);
		printf("          %2i |      %.3fs |             %.3fs\n", max_number, time_bf, time_dc);
	}

	// Übung 1.3 (2)
	min_number = 0;
	max_number = 100;
	int secret_numbers[] = {3, 13, 37, 73};
	printf("EXERCISE 1.3 (1)\n");
	printf("Secret number | Brute-force | Divide-and-conquer\n");
	for (int i = 0; i < 4; i++)
	{
		secret_number = secret_numbers[i];
		double time_bf = measure_time(min_number, max_number, find_number_bf);
		double time_dc = measure_time(min_number, max_number, find_number_dc);
		printf("           %2i |      %.3fs |             %.3fs\n", secret_number, time_bf, time_dc);
	}
	printf("\n");
}