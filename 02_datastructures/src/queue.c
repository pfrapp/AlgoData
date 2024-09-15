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
    // TODO: Übung 2.3 (1b)
}

char queue_peek(Queue* q)
{
    char value = '\0';
    // TODO: Übung 2.3 (1b)
    return value;
}

char queue_dequeue(Queue* q)
{
    // TODO: Übung 2.3 (1b)
    return '\0';
}