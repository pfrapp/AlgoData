#ifndef QUEUE_H_
#define QUEUE_H_

#include "list.h"

typedef struct Queue Queue;
struct Queue
{
    List* list;
};

void queue_init(Queue *q);
void queue_print(Queue* q);
bool queue_empty(Queue* q);
void queue_enqueue(Queue* q, char value);
char queue_peek(Queue* q);
char queue_dequeue(Queue* q);

#endif // QUEUE_H_