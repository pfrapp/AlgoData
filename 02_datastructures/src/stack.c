#include <stdlib.h>
#include "stack.h"

void stack_init(Stack* s)
{
    s->list = (List*)malloc(sizeof(List));
    list_init(s->list);
}

void stack_print(Stack* s)
{
    list_print(s->list);
}

bool stack_empty(Stack* s)
{
    return list_empty(s->list);
}

void stack_push(Stack* s, char value)
{
    list_push_front(s->list, value);
}

char stack_top(Stack* s)
{
    char value = '\0';
    if (!stack_empty(s))
    {
        value = s->list->head->next->value;
    }
    return value;
}

char stack_pop(Stack* q)
{
    return list_pop_front(q->list);
}