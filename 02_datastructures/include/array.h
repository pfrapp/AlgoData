#ifndef ARRAY_H_
#define ARRAY_H_

typedef struct Array Array;
struct Array
{
    int capacity;
    int size;
    char* elements;
};

// Function to init an array
void array_init(Array* a, int capacity); // <-- Deklaration (Semicolon am Ende)
void array_print(Array* a);

// Diese Funktion fuegt 'value' am Index 'idx' ein,
// vorhandene Werte werden nach rechts verschoben.
void array_insert(Array* a, int idx, char value);

// Entfernen des Elements an der Stelle 'idx'.
// Restliche Element aufruecken lassen (Luecke schliessen).
// Rueckgabe des entfernten Elements.
char array_remove(Array* a, int idx);

void array_push_back(Array* a, char value);
char array_pop_back(Array* a);

#endif // ARRAY_H_