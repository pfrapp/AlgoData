#include <stdio.h>
#include "array_utility.h"
#include "bubblesort.h"
#include "insertsort.h"
#include "selectsort.h"

void clear_input_buffer()
{
	char c = '\0';
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

int main()
{
	for (;;)
	{
		char data[] = { 'c','a','f','b','f','g' };
		
		printf("Please select sorting algorithm:\n");
		printf("1 = Selectsort\n");
		printf("2 = Insertsort\n");
		printf("3 = Bubblesort\n");
		char sel = getchar();

		printf("Original: "); array_print(data, sizeof(data));
		switch (sel)
		{
		case '1':
			selectsort(data, 0, sizeof(data) - 1);
			break;
		case '2':
			insertsort(data, 0, sizeof(data) - 1);
			break;
		case '3':
			bubblesort(data, 0, sizeof(data) - 1);
			break;
		default:
			printf("Invalid selection.\n");
		}
		printf("Sorted:   "); array_print(data, sizeof(data));
		printf("--------------------------------\n");
		clear_input_buffer();
	}
}