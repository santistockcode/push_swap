/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:38:21 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/09 18:19:00 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	char	**input;
	char	*str;

	a = NULL;
	input = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	str = ft_join_spaces(argv, argc);
	input = ft_split_ps(str);
	free(str);
	if (input)
		a = valid_input_and_list(input);

	if (!(a))
		print_error();
	else
	{
		if (!is_ordered(a))
			order_a(a);
		ft_lstclear(&a, free);
	}
	free_argv(input);
	return (0);
}
