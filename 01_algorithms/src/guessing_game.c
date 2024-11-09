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
	for (int guess = min_number; guess <= max_number; guess++)
	{
		if (response(guess) == 0)
		{
			return guess;
		}
	}
	return -1; // Number not found. Should never happen.
}

/**
 * Find number using a divide-and-conquer approach
 */
int find_number_dc(int min_number, int max_number)
{
	int result = 0;
	int guess = 0;
	do {
		guess = (max_number + min_number) / 2;
		result = response(guess);
		if (result > 0)
		{
			// Number is greater than guess, increase min_number
			min_number = guess + 1;
		}
		else if (result < 0)
		{
			// Number is less than guess, decrease max_number
			max_number = guess - 1;
		}
	} while (result != 0);

	return guess;
}

/**
 * Find number using a recursive divide-and-conquer approach
 */
int find_number_dcr(int min_number, int max_number)
{
	int guess = (max_number + min_number) / 2;
	int result = response(guess);
	if (result > 0)
	{
		// Number is greater than guess, increase min_number
		return find_number_dcr(guess + 1, max_number);
	}
	else if (result < 0)
	{
		// Number is less than guess, decrease max_number
		return find_number_dcr(min_number, guess - 1);
	}
	else // result == 0
	{
		return guess;
	}
}