#include "../include/push_swap.h"

int find_index_of(t_list *a_head, int number)
{
    t_list *current;
    int index;

    current = a_head;
    index = 0;
    while (current)
    {
        if (((t_number *)current->content)->value == number)
            return (index);
        current = current->next;
        index++;
    }
    return (-1);
}


void    update_indexes(t_list *a_head)
{
    t_list *current;
    int index;
    int size;

    current = a_head;
    index = 0;
    size = ft_lstsize(a_head);
    while (current)
    {
        ((t_number *)current->content)->index = index;
        ((t_number *)current->content)->is_upper_half = (index <= size / 2);
        current = current->next;
        index++;
    }
}

int is_ordered(t_list   *a_head)
{
    t_list *current;

    current = a_head;
    while (current && current->next)
    {
        if (((t_number *)current->content)->value > ((t_number *)current->next->content)->value)
            return (0);
        current = current->next;
    }
    return (1);
}

int find_min_number(t_list *a_head)
{
    t_list *current;
    int min_value;

    if (a_head == NULL)
        return (0);
    current = a_head;
    min_value = ((t_number *)current->content)->value;
    while (current)
    {
        if (((t_number *)current->content)->value < min_value)
            min_value = ((t_number *)current->content)->value;
        current = current->next;
    }
    return (min_value);
}

// function that returns max number in the stack. 
int find_max_number(t_list *a_head)
{
    t_list *current;
    int max_value;

    if (a_head == NULL)
        return (0);
    current = a_head;
    max_value = ((t_number *)current->content)->value;
    while (current)
    {
        if (((t_number *)current->content)->value > max_value)
            max_value = ((t_number *)current->content)->value;
        current = current->next;
    }
    return (max_value);
}
