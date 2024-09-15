#ifndef ARRAY_H_
#define ARRAY_H_

typedef struct Array Array;
struct Array
{
    int capacity;
    int size;
    char* elements;
};

void array_init(Array *a, int capacity);
void array_print(Array* a);
void array_insert(Array* a, int idx, char value);
char array_remove(Array* a, int idx);
void array_push_back(Array* a, char value);
char array_pop_back(Array* a);

#endif // ARRAY_H_