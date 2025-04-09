/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:38:21 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/09 08:16:56 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list *b;
	t_stacks    *stacks;

	char	**input;
	char	*str;

	a = NULL;
	b = NULL;
	input = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
    if (!stacks)
		return (0);
	str = ft_join_spaces(argv, argc);
	input = ft_split_ps(str);
	free(str);
	if (input)
		stacks->a_head = valid_input_and_list(input);
	stacks->b_head = b;
	if (!(stacks->a_head))
		print_error();
	else
		ft_lstclear(&(stacks->a_head), free);
	free_argv(input);
    free(stacks);
	return (0);
}