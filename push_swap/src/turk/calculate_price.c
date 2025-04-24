#include <stdio.h>
#include "../../include/push_swap.h"

int calc_price(int index, int size)
{
    if (index <= size / 2)
        return (index);
    else
        return (index - size);
}

static int absolute(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int calc_total(t_list *current)
{
    int price_a;
    int price_b;
    int abs_a;
    int abs_b;
    int total;

    total = 0;
    price_a = ((t_number *)current->content)->price_a;
    price_b = ((t_number *)current->content)->price_b;
    abs_a = absolute(price_a);
    abs_b = absolute(price_b);
    if ((price_a >= 0 && price_b >= 0) || (price_a <= 0 && price_b <= 0))
    {
        if (abs_a > abs_b)
            total = abs_a;
        else
            total = abs_b;
    }
    else
        total = abs_a + abs_b;
    return (total);
}

void    calculate_price(t_list *stack_a, t_list *stack_b)
{
    t_list *current;
    int size_a;
    int size_b;
    t_list *target;

    current = stack_a;
    size_a = ft_lstsize(stack_a);
    size_b = ft_lstsize(stack_b);
    while(current)
    {
        ((t_number *)current->content)->price_a =
            calc_price(((t_number *)current->content)->index, size_a);
        target = ((t_number *)current->content)->target_node;
        ((t_number *)current->content)->price_b =
            calc_price(((t_number *)target->content)->index, size_b);  
        ((t_number *)current->content)->total_price = calc_total(current); 
        current = current->next;
    }
}
