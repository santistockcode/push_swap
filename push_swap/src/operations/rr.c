#include "../../include/push_swap.h"

void rb_no_print(t_stacks *stacks)
{
    t_list* b_head;
    t_list* temp;

    b_head = stacks->b_head;
    if(b_head == NULL || b_head->next == NULL)
        return ;
    else
    {
        temp = b_head;
        stacks->b_head = temp;
        while(temp->next)
        {
            ft_swap(temp, temp->next);
            temp = temp->next;
        }
    }
}

void ra_no_print(t_stacks *stacks)
{
    t_list* a_head;
    t_list* temp;

    a_head = stacks->a_head;
    if(a_head == NULL || a_head->next == NULL)
        return ;
    else
    {
        temp = a_head;
        stacks->a_head = temp;
        while(temp->next)
        {
            ft_swap(temp, temp->next);
            temp = temp->next;
        }
    }
}

void rr(t_stacks *stacks)
{
    t_list* a_head;
    t_list* b_head;
    int flag;

    flag = 0;
    a_head = stacks->a_head;
    b_head = stacks->b_head;
    if(a_head == NULL || a_head->next == NULL)
        ;
    else
    {
        ra_no_print(stacks);
        flag = 1;
    }
    if(b_head == NULL || b_head->next == NULL)
        ;
    else
    {
        rb_no_print(stacks);
        flag = 1;
    }
    if (flag)
        write(1, "rr\n", 3);
}