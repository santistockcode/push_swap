/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_a_min_to_top.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:54:34 by saalarco          #+#    #+#             */
/*   Updated: 2025/05/01 11:13:21 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/push_swap.h"

void	rotate_stack_a_min_to_top(t_stacks *stacks)
{
	t_list	*current;
	int		min_value;
	int		index;
	int		a_size;

	current = stacks->a_head;
	min_value = find_min_number(stacks->a_head);
	while (current)
	{
		if (((t_number *)current->content)->value == min_value)
			break ;
		current = current->next;
	}
	index = ((t_number *)current->content)->index;
	a_size = ft_lstsize(stacks->a_head);
	if (((t_number *)current->content)->is_upper_half == 1)
	{
		while (index-- > 0)
			ra(stacks);
	}
	else
	{
		while (index++ < a_size)
			rra(stacks);
	}
}
