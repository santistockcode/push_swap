
#include "../include/push_swap.h"
#include "../include/parse_validation.h"

void	print_error()
{
    ft_putstr_fd("Error\n", 2);
}

int valid_input_and_list(char **argv)
{
    while (*argv)
    {
        // check for syntax errors
        
        // atol
        // check for max and min values integers 
        // check for duplicates IS EASIER IF LIST ALREADY THERE
        printf("Argument: %s\n", *argv);
        argv++;
    }
    return (1);
}