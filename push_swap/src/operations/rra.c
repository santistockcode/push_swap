// como encaminar esto

// En vez de en una función aparte ft_swap, tengo que guardarme el contenido e ir desplazando todo de forma que
// pasamos de 0 1 2 3 4 
// a 4 0 1 2 3

/* 0 1 2 3 4 */
/* 4 0 1 2 3*/

/* 0 1 2*/
/* 2 0 1*/


#include "../../include/push_swap.h"

void rra(t_stacks *stacks)
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
    write(1, "rra\n", 4);
}