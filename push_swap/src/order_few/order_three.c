#include <stdio.h>
#include "../../include/push_swap.h"

void order_three(t_stacks *stacks)
{
    t_list *a_head;

    a_head = stacks->a_head;
    if (is_ordered(a_head))
        return ;
    if(find_min_number(a_head) == ((t_number *)a_head->content)->value)
    {
        sa(stacks);
        ra(stacks);
        return ;
    }
    if(find_max_number(a_head) == ((t_number *)a_head->content)->value)
    {
        ra(stacks);
        if (is_ordered(a_head))
            return ;
        else
            sa(stacks);
        return ;
    }
    if (find_min_number(a_head) == ((t_number *)a_head->next->content)->value)
    {
        sa(stacks);
    }
    else if (find_max_number(a_head) == ((t_number *)a_head->next->content)->value)
    {
        rra(stacks);
    }
}
