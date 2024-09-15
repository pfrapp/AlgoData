#ifndef GUESSING_GAME_H_
#define GUESSING_GAME_H_

int secret_number;

int response(int guess);
int find_number_bf(int min_number, int max_number);
int find_number_dc(int min_number, int max_number);
int find_number_dcr(int min_number, int max_number);

#endif // GUESSING_GAME_H_
