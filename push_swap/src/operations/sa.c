
#include "../../include/push_swap.h"

void sa(t_stacks *stacks)
{
    t_list* a_head;

    a_head = stacks->a_head;
    if (a_head == NULL || a_head->next == NULL)
        return;
    ft_swap(a_head, a_head->next);
    write(1, "sa\n", 3);
}
