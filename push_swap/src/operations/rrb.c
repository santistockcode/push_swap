#include "../../include/push_swap.h"

void rrb(t_stacks *stacks)
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
    write(1, "rrb\n", 4);
}