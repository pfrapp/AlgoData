#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strfind.h"


#define BUFFER_SIZE (255)


void clear_input_buffer()
{
    char c = '\0';
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int readline(char *buffer, int buffer_len)
{
    char c;
    int len = 0;
    while (len < buffer_len && (c = getc(stdin)) != '\n')
    {
        buffer[len] = c;
        len++;
    }
    return len;
}


int main()
{
    /** Some Examples to try
     * 
     * Text: barbaras barbaren bar bier     Word: bar
     * Text: barbaras barbaren bar bier     Word: barbaren
     * Text: barbaras barbaren bar bier     Word: bier
     * Text: barbaras barbaren bar bier     Word: barbier
     * Text: aaaaaaaaaaaaab                 Word: aaab
     * Text: ddaabccababc                   Word: cababc
     */
    for(;;)
    {
        char word[BUFFER_SIZE], text[BUFFER_SIZE];
        int word_len = 0, text_len = 0;
        int pos = -1;

        printf("Choose algorithm (0 = BF, 1 = KMP, 2 = BMH): ");
        char algo = getchar();

        clear_input_buffer();

        printf("Please enter text: ");
        text_len = readline(text, BUFFER_SIZE);

        printf("Please enter word: ");
        word_len = readline(word, BUFFER_SIZE);
        
        switch(algo)
        {
            case '1':
                pos = strfind_kmp(word, word_len, text, text_len);
                break;
            case '2':
                pos = strfind_bmh(word, word_len, text, text_len);
                break;
            default: // 0
                pos = strfind_bf(word, word_len, text, text_len);
                break;
        }

        if(pos < 0)
        {
            printf("No match\n");
        }
        else
        {
            printf("Match at %i\n", pos);
        }
    }
    
    return 0;
}