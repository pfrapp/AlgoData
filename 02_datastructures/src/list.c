#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void list_init(List* l)
{
    l->head = (ListItem*) malloc(sizeof(ListItem));
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
    // TODO: Uebung 2.2 (1)

    // Siehe Folie 57 (Einfuegen und Loeschen
    // bei verketten Listen)

    // Im Bsp. auf der Folie ist das
    // 'item_to_be_removed' gleich Sophie.
    // 'item' entspricht Anna.
    // (Im Bsp. haben sind die Werte vom Typ
    // String, hier im Code haben wir characters)
    ListItem* item_to_be_removed = item->next;
    char return_value = '\0';

    if (item_to_be_removed != NULL) {
        // Anna zeigt jetzt auf Klaus.
        item->next = item_to_be_removed->next;
        return_value = item_to_be_removed->value;
        // Speicher freigeben
        // (Speicher an das OS zurueckgegben)
        free(item_to_be_removed);
    }

    return return_value;
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
    // TODO: �bung 2.2 (2)
    // Hinweis: �berpr�fen Sie auch die Implementierung von list_init, 
    // list_print, list_empty, list_insert_after und list_remove_after
}