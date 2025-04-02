#include "../../include/push_swap.h"


void pb(t_stacks *stacks)
{
    t_list* a_head;
    t_list* b_head;
    t_list* temp;

    a_head = stacks->a_head;
    b_head = stacks->b_head;
    if (a_head == NULL)
        return;
    temp = a_head;
    stacks->a_head = a_head->next;
    if(b_head == NULL)
    {
        stacks->b_head = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = b_head;
        stacks->b_head = temp;
    }
    write(1, "pb\n", 3);
}