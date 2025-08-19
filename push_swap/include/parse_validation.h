/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:25:07 by saalarco          #+#    #+#             */
/*   Updated: 2025/05/01 11:23:23 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_VALIDATION_H
# define PARSE_VALIDATION_H

# include "../libft/include/libft.h"

// This function checks if string has only '-', 
// spaces and digits and returns true or false
int		error_syntax(char *str);

// This function checks if there are duplicates 
//in the array and returns true or false
int		error_duplicates(t_list *list, int value);

// This function frees the memory allocated for the array
void	free_argv(char **argv);

// This function converts a string to a long integer
long	ft_atol(const char *str);

#endif