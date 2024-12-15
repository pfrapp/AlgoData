#include <stdlib.h>
#include "queue.h"

void queue_init(Queue* q)
{
    q->list = (List*)malloc(sizeof(List));
    list_init(q->list);
}

void queue_print(Queue* q)
{
    list_print(q->list);
}

bool queue_empty(Queue* q)
{
    return list_empty(q->list);
}

void queue_enqueue(Queue* q, char value)
{
    list_push_back(q->list, value);
}

char queue_peek(Queue* q)
{
    char value = '\0';
    if (!queue_empty(q))
    {
        value = q->list->head->next->value;
    }
    return value;
}

char queue_dequeue(Queue* q)
{
    return list_pop_front(q->list);
}