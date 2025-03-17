#include "../../include/push_swap.h"


int error_duplicates(t_list *list, int value)
{
    t_list *current;

    current = list;
    while (current)
    {
        if (((t_number *)current->content)->value == value)
            return (1);
        current = current->next;
    }
    return (0);
}
