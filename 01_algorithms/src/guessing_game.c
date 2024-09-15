#include "guessing_game.h"

/**
 * Response of player A
 *
 * Returns  0, if the guess is correct
 * Returns  1, if the guess is less than the secret number
 * Returns -1, if the guess is greater than the secret number
 */
int response(int guess)
{
	if (guess == secret_number)
	{
		return 0;	// Correct!
	}
	else if (guess < secret_number)
	{
		return 1;	// Bigger!
	}
	else if (guess > secret_number)
	{
		return -1;	// Smaller!
	}
}

/**
 * Find number using a brute-force approach
 */
int find_number_bf(int min_number, int max_number)
{
	// TODO: Übung 1.2 (1a)

	return -1;
}

/**
 * Find number using a divide-and-conquer approach
 */
int find_number_dc(int min_number, int max_number)
{
	// TODO: Übung 1.2 (1b)

	return -1;
}