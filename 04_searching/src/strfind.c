#include <stdio.h>
#include <stdlib.h>
#include "strfind.h"

/** Helper functions **/

void print_strfind(char word[], int word_len, int word_pos, char text[], int text_len, int text_pos)
{
    char *col = "\x1B[31m";
    if(word[word_pos] == text[text_pos])
    {
        col = "\x1B[32m";
    }
    for(int i = 0; i < text_len; i++)
    {
        if (i == text_pos) printf("%s%c\033[0m", col, text[i]);
        else printf("%c", text[i]);
    }
    printf("\n");
    for(int i = 0; i < text_pos-word_pos; i++) 
    {
        printf(" ");
    }
    for(int i = 0; i < word_len; i++)
    {
        if(i == word_pos) printf("%s%c\033[0m", col, word[i]);
        else printf("%c", word[i]);
    }
    printf("\n");
    for(int i = 0; i < text_len; i++)
    {
        printf("-");
    }
    printf("\n");
}


/** Brute-Force **/

int strfind_bf(char word[], int word_len, char text[], int text_len)
{
    int i = 0, j = 0;
    while(i <= (text_len - word_len))
    {
        print_strfind(word, word_len, j, text, text_len, i+j);
        if(text[i+j] == word[j])
        {
            j++;
            if(j == word_len)
            {
                return i;
            }
        }
        else
        {
            i++;
            j = 0;
        }
    }
    return -1;
}


/** Knuth-Morris-Pratt **/

void init_kmp_table(char word[], int word_len, int table[])
{
    int j = 1;
    int len = 0;
    table[0] = 0;
    while (j < word_len)
    {
        if (word[j] == word[len])
        {
            len++;
            table[j] = len;
            j++;
        }
        else
        {
            if (len != 0)
            {
                len = table[len - 1];
            }
            else
            {
                table[j] = 0;
                j++;
            }
        }
    }
}

int strfind_kmp(char word[], int word_len, char text[], int text_len)
{
    // Initialize table
    int *table = (int*)malloc(word_len * sizeof(int));
    init_kmp_table(word, word_len, table);

    // Find word
    int i = 0, j = 0;
    while(i-j <= (text_len-word_len))
    {
        print_strfind(word, word_len, j, text, text_len, i);
        if(text[i] == word[j])
        {
            i++;
            j++;
            if(j == word_len)
            {
                free(table);
                return i-j;
            }
        }
        else
        {
            if(j == 0)
            {
                i++;
            }
            else
            {
                j = table[j-1];
            }
        }
    }   
    free(table);
    return -1;
}


/** Boyer-Moore-Horspool **/


#define ASCII_SIZE  256

void init_bmh_table(char word[], int word_len, int table[])
{
    for(int j = 0; j < ASCII_SIZE; j++)
    {
        table[j] = word_len;
    }
    for(int j = 0; j < word_len-1; j++)
    {
        table[(int) word[j]] = word_len - j - 1;
    }
}

int strfind_bmh(char word[], int word_len, char text[], int text_len)
{
    // Initialize table
    int* table = malloc(ASCII_SIZE * sizeof(int));
    init_bmh_table(word, word_len, table);

    // Find word
    int i = 0, j = word_len-1;
    while(i <= (text_len-word_len))
    {
        print_strfind(word, word_len, j, text, text_len, i+j);
        if(text[i+j] == word[j])
        {
            j--;
            if(j < 0)
            {
                free(table);
                return i;
            }
        }
        else
        {
            i += table[(int) text[i + word_len - 1]];
            j = word_len-1;
        }
    }   
    free(table);
    return -1;
}