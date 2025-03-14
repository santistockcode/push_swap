
#include "../include/push_swap.h"
#include "../include/parse_validation.h"

void	print_error()
{
    ft_putstr_fd("Error\n", 2);
}

t_list  *valid_input_and_list(char **argv)
{
    long l;
    t_list *list;
    t_number *number;
    int counter;

    counter = 0;
    list = NULL;
    while (*argv)
    {
        // check for syntax errors
        
        // atol
        l = ft_atol(*argv);
        // check for max and min values integers 

        // create number
        number = (t_number *)malloc(sizeof(t_number));
        if (!number)
            return (NULL);
        number->value = (int) l;
        number->index = counter++;
        // add to list
        t_list *new_node = ft_lstnew(number);
        if (!new_node)
            return (NULL);
        ft_lstadd_back(&list, new_node);
        // TODO: lstnew might fail, PROTECT

        // check for duplicates in list

        printf("ADDED to list: %ld\n", l);
        argv++;
    }
    return (list);
}