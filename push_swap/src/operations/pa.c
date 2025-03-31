#include "../../include/push_swap.h"

void pa(t_stacks *stacks)
{
    t_list* a_head;
    t_list* b_head;
    t_list* temp;

    a_head = stacks->a_head;
    b_head = stacks->b_head;
    if (b_head == NULL)
        return;
    temp = b_head;
    stacks->b_head = b_head->next;
    if(a_head == NULL)
    {
        stacks->a_head = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = a_head;
        stacks->a_head = temp;
    }
    write(1, "pa\n", 3);
}