/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input_and_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:16:18 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/07 18:18:50 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/parse_validation.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

int	valid_input(char **argv, t_list **list, long *l)
{
	if (error_syntax(*argv))
		return (0);
	*l = ft_atol(*argv);
	if (*l > INT_MAX || *l < INT_MIN)
		return (0);
	if (error_duplicates(*list, *l))
		return (0);
	return (1);
}

t_list	*valid_input_and_list(char **argv)
{
	long		l;
	t_list		*list;
	t_number	*number;
	int			counter;
	t_list		*new_node;

	counter = 0;
	list = NULL;
	l = 0;
	while (*argv != NULL)
	{
		if (!valid_input(argv, &list, &l))
			return (ft_lstclear(&list, free), NULL);
		number = (t_number *)malloc(sizeof(t_number));
		if (!number)
			return (NULL);
		number->value = (int) l;
		number->index = counter++;
		new_node = ft_lstnew(number);
		if (!new_node)
			return (ft_lstclear(&list, free), NULL);
		ft_lstadd_back(&list, new_node);
		argv++;
	}
	return (list);
}
