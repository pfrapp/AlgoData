#ifndef STRFIND_H_
#define STRFIND_H_

// Brute-force
int strfind_bf(char word[], int word_size, char text[], int text_size);

// Knuth-Morris-Pratt
int strfind_kmp(char word[], int word_size, char text[], int text_size);

// Boyer-Moore-Horspool
int strfind_bmh(char word[], int word_size, char text[], int text_size);

#endif // STRFIND_H_
