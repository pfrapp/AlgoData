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
    a->elements = (char*) malloc(capacity);
}

void array_resize(Array* a, int new_capacity)
{
    if (new_capacity != a->capacity)
    {
        // Allocate new memory
        char* new_elements = (char*)malloc(new_capacity);
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
    // Increase size if necessary
    if (a->size >= a->capacity)
    {
        int new_capacity = 2 * a->capacity;
        if (new_capacity == 0) new_capacity = 1;
        array_resize(a, new_capacity);
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
    // Save element to be removed
    char temp = a->elements[idx];

    // Copy all elements after idx to the left, overriding the element to be removed
    a->size--;
    for (int i = idx; i < a->size; ++i)
    {
        a->elements[i] = a->elements[i + 1];
    }

    // Shrink if needed
    if (a->size <= a->capacity / 4)
    {
        int new_capacity = a->capacity / 2;
        if (new_capacity == 0) new_capacity = 1;
        array_resize(a, new_capacity);
    }

    return temp;
}

void array_push_back(Array* a, char value)
{
    array_insert(a, a->size, value);
}

char array_pop_back(Array* a)
{
    return array_remove(a, a->size - 1);
}

