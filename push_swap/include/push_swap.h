
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "parse_validation.h"

typedef struct s_number
{
    int	value;
    int	index;
}	t_number;


// This function splits the string into an array of strings representing numbers
char **ft_split_ps(char *str);

// This function prints "Error" to the standard error output
void	print_error();

// This function checks if the input is valid
t_list  *valid_input_and_list(char **argv);

void    free_argv(char **argv);

void    print_list(t_list *head);

#endif
