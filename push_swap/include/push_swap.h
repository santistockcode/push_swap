
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

// This function prints "Error" to the standard error output
void	print_error();

// This function checks if string has only '-', spaces and digits and returns true or false
int error_syntax(char *str);

// This function checks if there are duplicates in the array and returns true or false
int error_duplicates(char **argv);

// This function frees the memory allocated for the array
void free_argv(char **argv);

// This function splits the string into an array of strings representing numbers
char **ft_split_ps(char *str);
#endif
