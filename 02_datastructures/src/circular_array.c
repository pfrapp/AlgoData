#include <stdio.h>
#include <stdlib.h>
#include "circular_array.h"

void circular_array_print(CircularArray* a)
{
    for (int i = 0; i < a->capacity; i++)
    {
        int k = (a->capacity + i - a->first) % a->capacity;
        if (k < a->size)
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

void circular_array_init(CircularArray*a, int capacity)
{
    a->capacity = capacity;
    a->first = 0;
    a->size = 0;
    a->elements = (char*) malloc(capacity);
}

void circular_array_resize(CircularArray* a, int new_capacity)
{
    if (new_capacity != a->capacity)
    {
        // Allocate new memory
        char *new_elements = (char*) malloc(new_capacity);
        // Copy data from old to new memory, starting at 0
        for (int k = 0; k < a->size; ++k)
        {
            int i = (a->first + k) % a->capacity;
            new_elements[k] = a->elements[i];
        }
        // Free old memory
        free(a->elements);
        // Store new memory location and capacity
        a->first = 0;
        a->elements = new_elements;
        a->capacity = new_capacity;
    }
}

void circular_array_insert(CircularArray*a, int idx, char value)
{
    // Increase size if necessary
    if (a->size >= a->capacity)
    {
        int new_capacity = 2 * a->capacity;
        if (new_capacity == 0) new_capacity = 1;
        circular_array_resize(a, new_capacity);
    }

    if (idx >= a->size / 2)
    {
        // Copy all elements after idx to the right
        for (int k = a->size; k > idx; --k)
        {
            int new_i = (a->first + k) % a->capacity;
            int old_i = (a->capacity + a->first + k - 1) % a->capacity;
            a->elements[new_i] = a->elements[old_i];
        }
    }
    else
    {
        // Determine new first
        a->first = (a->capacity + a->first - 1) % a->capacity;
        // Copy all elements before idx to the left
        for (int k = 0; k < idx; ++k)
        {
            int new_i = (a->first + k) % a->capacity;
            int old_i = (a->capacity + a->first + k - 1) % a->capacity;
            a->elements[new_i] = a->elements[old_i];
        }
    }
    // Insert new element at idx
    int i = (a->first + idx) % a->capacity;
    a->elements[i] = value;
    a->size++;
}

char circular_array_remove(CircularArray* a, int idx)
{
    // Save element to be removed
    char temp = a->elements[idx];

    a->size--;
    if (idx >= a->size / 2)
    {
        // Copy all elements after idx to the left, overriding the element to be removed
        for (int k = idx; k < a->size; ++k)
        {
            int new_i = (a->first + k) % a->capacity;
            int old_i = (a->first + k + 1) % a->capacity;
            a->elements[new_i] = a->elements[old_i];
        }
    }
    else
    {
        // Copy all elements before idx to the right, overriding the element to be removed
        for (int k = idx; k >= 0; --k)
        {
            int new_i = (a->first + k) % a->capacity;
            int old_i = (a->capacity + a->first + k - 1) % a->capacity;
            a->elements[new_i] = a->elements[old_i];
        }
        // Determine new first
        a->first = (a->first + 1) % a->capacity;
    }

    // Shrink if needed
    if (a->size <= a->capacity / 4)
    {
        int new_capacity = a->capacity / 2;
        if (new_capacity == 0) new_capacity = 1;
        circular_array_resize(a, new_capacity);
    }

    return temp;
}

void circular_array_push_back(CircularArray* a, char value)
{
    circular_array_insert(a, a->size, value);
}

char circular_array_pop_back(CircularArray* a)
{
    return circular_array_remove(a, a->size - 1);
}

void circular_array_push_front(CircularArray* a, char value)
{
    circular_array_insert(a, 0, value);
}

char circular_array_pop_front(CircularArray* a)
{
    return circular_array_remove(a, 0);
}

