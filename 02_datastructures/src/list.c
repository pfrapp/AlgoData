#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void list_init(List* l)
{
    l->head = (ListItem*) malloc(1);
    l->tail = (ListItem*) malloc(1);
    l->head->next = l->tail;
    l->tail->next = l->head;
    l->head->value = '\0';
    l->tail->value = '\0';
}

void list_print(List* l)
{
    ListItem* item = l->head;
    while (item->next != l->tail)
    {
        item = item->next;
        printf("%c", item->value);
        if (item->next != l->tail)
        {
            printf(", ");
        }
    }
    printf("\n");
}

bool list_empty(List* l)
{
    return l->head->next == l->tail;
}

ListItem* list_insert_after(List* l, ListItem* item, char value)
{
    ListItem* new_item = (ListItem*) malloc(sizeof(ListItem));
    new_item->value = value;
    new_item->next = item->next;
    item->next = new_item;
    if (new_item->next == l->tail) l->tail->next = new_item;
    return new_item;
}

char list_remove_after(List* l, ListItem* item)
{
    ListItem* del_item = item->next;
    char value = '\0';
    if (del_item != l->tail)
    {
        value = del_item->value;
        item->next = del_item->next;
        if (item->next == l->tail) l->tail->next = item;
        free(del_item);
    }
    return value;
}

ListItem* list_push_front(List* l, char value)
{
    return list_insert_after(l, l->head, value);
}

char list_pop_front(List* l)
{
    return list_remove_after(l, l->head);
}

ListItem* list_push_back(List* l, char value)
{
    return list_insert_after(l, l->tail->next, value);
}