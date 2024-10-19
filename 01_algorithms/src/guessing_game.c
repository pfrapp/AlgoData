#include "guessing_game.h"

int secret_number;

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
	// Uebung 1.2 (1a)

	// Use this variable for the given response.
	int resp;

	// Current guess
	int current_guess;

	for (current_guess = min_number; current_guess <= max_number; current_guess++) {
		// Ask about the secret number.
		resp = response(current_guess);

		if (resp == 0) {
			return current_guess;
		}
	}

	return -1;
}

/**
 * Find number using a divide-and-conquer approach
 */
int find_number_dc(int min_number, int max_number)
{
	// Uebung 1.2 (1b)

	// Center of bisectioning.
	int separation;

	// Answer/reponse.
	int resp;

	while(1) {

		separation = (min_number + max_number) / 2;
		resp = response(separation);

		switch(resp) {
			case 0:
				return separation;
			case 1:
				// Guess is less than secret number.
				// Secret number is bigger.

				// min_number rueckt auf separation auf,
				// um das Intervall zu schachteln.
				min_number = separation;
				break;

			case -1:
				// Guess is greater than secret number.
				// Secret number is smaller.
				max_number = separation;
				break;
		}
	}

	return -1;
}

int find_number_dcr(int min_number, int max_number) {
	int separation;
	int resp;

	separation = (min_number + max_number) / 2;
	resp = response(separation);

	if (0 == resp) {
		return separation;
	} else if (1 == resp) {
		// Guess is less than secret number.
		// Secret number is bigger.

		// Intervall
		// [separation, max_number]
		return find_number_dcr(separation, max_number);
	} else if (-1 == resp) {
		return find_number_dcr(min_number, separation);
	}

	return -1;
}