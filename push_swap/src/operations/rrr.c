#include "../../include/push_swap.h"

void rrb_no_print(t_stacks *stacks)
{
    t_list* b_head;
    t_list* temp;
    void*   paso;
    void*   st;
    t_list* start;

    b_head = stacks->b_head;
    if(b_head == NULL || b_head->next == NULL)
        return ;
    else
    {
        temp = b_head;
        start = b_head; 
        st = temp->content;
        paso = temp->next->content;
        temp->next->content = st;
        temp = temp->next;
        while(temp->next)
        {
            st = temp->next->content;
            temp->next->content = paso;
            paso = st;
            temp = temp->next;
        }
        start->content = paso;
    }
}

void rra_no_print(t_stacks *stacks)
{
    t_list* a_head;
    t_list* temp;
    void*   paso;
    void*   st;
    t_list* start;

    a_head = stacks->a_head;
    if(a_head == NULL || a_head->next == NULL)
        return ;
    else
    {
        temp = a_head;
        start = a_head; 
        st = temp->content;
        paso = temp->next->content;
        temp->next->content = st;
        temp = temp->next;
        while(temp->next)
        {
            st = temp->next->content;
            temp->next->content = paso;
            paso = st;
            temp = temp->next;
        }
        start->content = paso;
    }
}

void rrr(t_stacks *stacks)
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
        rra_no_print(stacks);
        flag = 1;
    }
    if(b_head == NULL || b_head->next == NULL)
        ;
    else
    {
        rrb_no_print(stacks);
        flag = 1;
    }
    if (flag)
        write(1, "rrr\n", 4);
}