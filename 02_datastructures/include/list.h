#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

typedef struct ListItem ListItem;
struct ListItem
{
    ListItem* next;
    char value;
};

typedef struct List List;
struct List
{
    ListItem* head;
};

void list_init(List *l);
void list_print(List* l);
bool list_empty(List* l);
ListItem* list_insert_after(List* l, ListItem* item, char value);
char list_remove_after(List* l, ListItem* item);
ListItem* list_push_front(List* l, char value);
char list_pop_front(List* l);
ListItem* list_push_back(List* l, char value);

#endif // LIST_H_