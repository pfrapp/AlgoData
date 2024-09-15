#ifndef STACK_H_
#define STACK_H_

#include "list.h"

typedef struct Stack Stack;
struct Stack
{
    List* list;
};

void stack_init(Stack* s);
void stack_print(Stack* s);
bool stack_empty(Stack* s);
void stack_push(Stack* s, char value);
char stack_top(Stack* s);
char stack_pop(Stack* s);

#endif // STACK_H_