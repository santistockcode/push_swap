
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "parse_validation.h"

// This function splits the string into an array of strings representing numbers
char **ft_split_ps(char *str);

// This function prints "Error" to the standard error output
void	print_error();

// This function checks if the input is valid
int valid_input_and_list(char **argv);

void    free_argv(char **argv);

#endif
