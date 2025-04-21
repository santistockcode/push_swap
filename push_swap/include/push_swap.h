/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:25:11 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/21 09:47:44 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "parse_validation.h"
# include "operations.h"
# include "order.h"
# include "order_few.h"
# include "turk.h"

typedef struct s_number
{
    int	value;
    int	index;
    int is_upper_half;
    t_list *target_node;
    int price_a;
    int price_b;
    int total_price;
    int is_cheapest;
}	t_number;


// This function splits the string into an array of strings representing numbers
char **ft_split_ps(char *str);

// This function prints "Error" to the standard error output
void	print_error();

// This function checks if the input is valid
t_list  *valid_input_and_list(char **argv);

// This function joins every argument with a space in betwee
char    *ft_join_spaces(char **argv, int argc);

// This util function print list
void    print_list(t_list *head);


#endif
