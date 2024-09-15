#include <stdio.h>
#include "array.h"

int main()
{
    // Create array and reserve some space;
    Array my_array;
    array_init(&my_array, 3);

    // Insert some elements and print array
    array_push_back(&my_array, 'a');
    array_push_back(&my_array, 'b');
    array_insert(&my_array, 1, 'c');
    array_print(&my_array);

    // Remove element and print
    array_remove(&my_array, 1);
    array_print(&my_array);

    // Insert more elements, exceeding the capacity
    array_push_back(&my_array, 'd');
    array_push_back(&my_array, 'e');
    array_print(&my_array);

    // Remove some elements
    array_pop_back(&my_array);
    array_pop_back(&my_array);
    array_print(&my_array);
    array_pop_back(&my_array);
    array_print(&my_array);

    return 0;
}