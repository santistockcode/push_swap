#include "../include/push_swap.h"

void    order_a(t_list  *a_head)
{
    t_stacks *stacks;
    int      size;

    stacks = (t_stacks *)malloc(sizeof(t_stacks));
    if (!stacks)
        return ;
    stacks->a_head = a_head;
    stacks->b_head = NULL;
    size = ft_lstsize(a_head);
    update_indexes(stacks->a_head);
    if (size == 2)
        sa(stacks);
    else if (size == 3)
        order_three(stacks);
    else if (size <= 5)
        order_five(stacks);
    else
        order_many(stacks);
    free(stacks);
}
