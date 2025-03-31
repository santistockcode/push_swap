#include "../../include/push_swap.h"

void ft_swap(t_list *a, t_list *b)
{
    void *temp;

    temp = a->content;
    a->content = b->content;
    b->content = temp;
}