#include "../../include/push_swap.h"

void ss(t_stacks *stacks)
{
    t_list* a_head;
    t_list* b_head;

    a_head = stacks->a_head;
    b_head = stacks->b_head;
    if (a_head == NULL || a_head->next == NULL)
        return;
    else
        ft_swap(a_head, a_head->next);
    if (b_head == NULL || b_head->next == NULL)
        return;
    else
        ft_swap(b_head, b_head->next);
    write(1, "ss\n", 3);
}