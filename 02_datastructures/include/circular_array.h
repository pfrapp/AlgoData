#ifndef CIRCULAR_ARRAY_H_
#define CIRCULAR_ARRAY_H_

typedef struct CircularArray CircularArray;
struct CircularArray
{
    int capacity;
    int first;
    int size;
    char* elements;
};

void circular_array_init(CircularArray*a, int capacity);
void circular_array_print(CircularArray* a);
void circular_array_insert(CircularArray* a, int idx, char value);
char circular_array_remove(CircularArray* a, int idx);
void circular_array_push_back(CircularArray* a, char value);
char circular_array_pop_back(CircularArray* a);
void circular_array_push_front(CircularArray* a, char value);
char circular_array_pop_front(CircularArray* a);

#endif // CIRCULAR_ARRAY_H_