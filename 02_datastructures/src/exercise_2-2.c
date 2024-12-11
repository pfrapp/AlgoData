#include <stdio.h>
#include "list.h"

int main()
{
    // Create array and reserve some space;
    List my_list;
    list_init(&my_list);

    // Insert some elements at the front
    ListItem* item;
    for (char c = 'a'; c < 'd'; c++)
    {
        item = list_push_front(&my_list, c);
        list_print(&my_list);
    }

    // Insert an element after the last inserted element
    printf("Inserting x\n");
    item = list_insert_after(&my_list, item, 'x');
    list_print(&my_list);

    // Remove after the newly inserted item.
    // (muss noch implementiert werden)
    printf("Removing element\n");
    char value = list_remove_after(&my_list, item);
    printf("Removed element with value %c\n", value);
    list_print(&my_list);
    return 0;

    // Insert some elements at the back (requires tail!)
    for (char c = 'd'; c < 'g'; c++)
    {
        item = list_push_back(&my_list, c);
        list_print(&my_list);
    }

    // Remove elements until empty
    while (!list_empty(&my_list))
    {
        list_pop_front(&my_list);
        list_print(&my_list);
    }

    return 0;
}