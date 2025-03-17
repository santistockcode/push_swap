/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:38:21 by saalarco          #+#    #+#             */
/*   Updated: 2025/03/17 19:42:10 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	char	**input;

	a = NULL;
	input = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
	{
		return (0);
	}
	if (argc == 2)
		input = ft_split_ps(argv[1]);
	else
		input = ++argv;
	if (input)
		a = valid_input_and_list(input);
    // here we call order list and print moves function
	if (a)
		ft_lstclear(&a, free);
	else
		print_error();
	if (argc == 2)
		free_argv(input);
	return (0);
}