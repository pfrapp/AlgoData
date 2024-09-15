#include <stdio.h>
#include "stack.h"
#include "queue.h"

int main()
{
    // Stack
    printf("Stack (LIFO):\n");
    Stack my_stack;
    stack_init(&my_stack);
    for (char c = 'a'; c < 'f'; c++)
    {
        stack_push(&my_stack, c);
        stack_print(&my_stack);
    }
    while (!stack_empty(&my_stack))
    {
        stack_pop(&my_stack);
        stack_print(&my_stack);
    }

    // Queue
    printf("Queue (FIFO):\n");
    Queue my_queue;
    queue_init(&my_queue);
    for (char c = 'a'; c < 'f'; c++)
    {
        queue_enqueue(&my_queue, c);
        queue_print(&my_queue);
    }
    while (!queue_empty(&my_queue))
    {
        queue_dequeue(&my_queue);
        queue_print(&my_queue);
    }

    return 0;
}