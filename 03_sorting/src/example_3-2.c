#include <stdio.h>
#include <stdlib.h>
#include "array_utility.h"
#include "heap_sort.h"
#include "merge_sort.h"
#include "quicksort.h"

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
		printf("1 = Mergesort\n");
		printf("2 = Quicksort\n");
		printf("3 = Heapsort\n");
		char sel = getchar();

		printf("Original: "); array_print(data, sizeof(data));
		switch (sel)
		{
		case '1': {
			char* temp = (char*)malloc(sizeof(data));
			merge_sort(data, temp, 0, sizeof(data) - 1);
			free(temp);
			break;
		}
		case '2': {
			quicksort(data, 0, sizeof(data) - 1);
			break;
		}
		case '3': {
			heap_sort(data, 0, sizeof(data) - 1);
			break;
		}
		default:
			printf("Invalid selection.\n");
		}
		printf("Sorted:   "); array_print(data, sizeof(data));
		printf("--------------------------------\n");
		clear_input_buffer();
	}
}