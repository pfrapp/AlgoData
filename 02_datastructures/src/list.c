#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void list_init(List* l)
{
    l->head = (ListItem*) malloc(1);
    l->head->next = NULL;
    l->head->value = '\0';
}

void list_print(List* l)
{
    ListItem* item = l->head;
    while (item->next != NULL)
    {
        item = item->next;
        printf("%c", item->value);
        if (item->next != NULL)
        {
            printf(", ");
        }
    }
    printf("\n");
}

bool list_empty(List* l)
{
    return l->head->next == NULL;
}

ListItem* list_insert_after(List* l, ListItem* item, char value)
{
    ListItem* new_item = (ListItem*) malloc(sizeof(ListItem));
    new_item->value = value;
    new_item->next = item->next;
    item->next = new_item;
    return new_item;
}

char list_remove_after(List* l, ListItem* item)
{
    // TODO: Übung 2.2 (1)

    return '\0';
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
    // TODO: Übung 2.2 (2)
    // Hinweis: Überprüfen Sie auch die Implementierung von list_init, 
    // list_print, list_empty, list_insert_after und list_remove_after
}