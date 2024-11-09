#include <stdio.h>
#include "circular_array.h"

int main()
{
    // Create array and reserve some space;
    CircularArray my_array;
    circular_array_init(&my_array, 6);

    // Insert some elements and print array
    circular_array_push_back(&my_array, 'a');
    circular_array_push_back(&my_array, 'b');
    circular_array_insert(&my_array, 1, 'c');
    circular_array_push_front(&my_array, 'd');
    circular_array_insert(&my_array, 0, 'e');
    circular_array_insert(&my_array, 2, 'f');
    circular_array_print(&my_array);

    // Insert one more element, exceeding capacity
    circular_array_insert(&my_array, 4, 'g');
    circular_array_print(&my_array);


    // Remove element and print
    circular_array_remove(&my_array, 1);
    circular_array_print(&my_array);
    circular_array_remove(&my_array, 4);
    circular_array_print(&my_array);

    // Remove some elements
    circular_array_pop_back(&my_array);
    circular_array_pop_front(&my_array);
    circular_array_print(&my_array);
    circular_array_pop_back(&my_array);
    circular_array_print(&my_array);

    return 0;
}