#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void array_print(Array* a)
{
    for (int i = 0; i < a->capacity; i++)
    {
        if (i < a->size)
        {
            printf("%c", a->elements[i]);
        }
        else
        {
            printf("-");
        }
        if (i < a->capacity - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
}

void array_init(Array *a, int capacity)
{
    a->capacity = capacity;
    a->size = 0;
    a->elements = (char*) malloc(capacity * sizeof(char));
}

void array_resize(Array* a, int new_capacity)
{
    if (new_capacity != a->capacity)
    {
        // Allocate new memory
        char *new_elements = (char*) malloc(new_capacity * sizeof(char));
        // Copy data from old to new memory
        for (int i = 0; i < a->size; ++i)
        {
            new_elements[i] = a->elements[i];
        }
        // Free old memory
        free(a->elements);
        // Store new memory location and capacity
        a->elements = new_elements;
        a->capacity = new_capacity;
    }
}

void array_insert(Array *a, int idx, char value)
{
    // Uebung 2.1 (2)
    if (a->size >= a->capacity) {
        array_resize(a, 2*a->capacity);
    }

    // Copy all elements after idx to the right
    for (int i = a->size; i > idx; --i)
    {
        a->elements[i] = a->elements[i - 1];
    }
    // Insert new element at idx
    a->elements[idx] = value;
    a->size++;
}

char array_remove(Array* a, int idx)
{
    // Uebung 2.1 (1)
    // Save element to be removed
    char removed_element = a->elements[idx];
    // Decrement size
    a->size--;
    // Copy elements from right to left, that is,
    // start with the left-most element
    // in order to not overwrite the elements
    // too early.
    for (int ii = idx; ii < a->size; ii++) {
        a->elements[ii] = a->elements[ii+1];
    }

    // Uebung 2.1 (2)
    if (a->size <= a->capacity / 4) {
        int new_capacity = a->capacity / 2;
        if (new_capacity < 1) {
            new_capacity = 1;
        }
        array_resize(a, new_capacity);
    }

    return '\0';
}

void array_push_back(Array* a, char value)
{
    array_insert(a, a->size, value);
}

char array_pop_back(Array* a)
{
    return array_remove(a, a->size - 1);
}

