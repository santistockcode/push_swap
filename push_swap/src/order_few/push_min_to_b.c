#include <stdio.h>
#include "../../include/push_swap.h"

void	push_min_to_b(t_stacks *stacks)
{
    int index;
    t_list *current;
    int counter;

    index = find_index_of(stacks->a_head, find_min_number(stacks->a_head));
    
    current = stacks->a_head;
    counter = 0;
    while(counter < index)
    {
        current = current->next;
        counter++;
    }
    if (((t_number *)current->content)->is_upper_half)
    {
        while(counter-- > 0)
            ra(stacks);
    }
    else
    {
        while(counter++ < ft_lstsize(stacks->a_head))
            rra(stacks);
    }
    pb(stacks);
}
