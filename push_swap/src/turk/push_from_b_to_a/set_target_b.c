/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:54:05 by saalarco          #+#    #+#             */
/*   Updated: 2025/05/01 10:54:06 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../include/push_swap.h"

void	assign_min_target(t_list *node_a, t_list *stack_b, int index)
{
	t_list	*current;
	int		counter;

	current = stack_b;
	counter = 0;
	while (current)
	{
		if (index == counter)
		{
			((t_number *)node_a->content)->target_node = current;
			return ;
		}
		counter++;
		current = current->next;
	}
}

void	eval_min_and_set_target(t_list *node_b, t_list *stack_a)
{
	t_list	*proposal;
	int		value_a;
	int		value_b;
	int		min;
	int		best;

	min = INT_MAX;
	best = INT_MAX;
	value_b = ((t_number *)node_b->content)->value;
	proposal = stack_a;
	while (proposal)
	{
		value_a = ((t_number *)proposal->content)->value;
		if (value_a > value_b && value_a < best)
		{
			((t_number *)node_b->content)->target_node = proposal;
			best = value_a;
		}
		else if (value_a < min)
			min = value_a;
		proposal = proposal->next;
	}
	if (best == INT_MAX)
		assign_min_target(node_b, stack_a, find_index_of(stack_a, min));
}

/*
target = “closest smaller value in B” 
		 (or max‑value‑in‑B if none is smaller)
*/
void	set_target_b(t_list *stack_b, t_list *stack_a)
{
	t_list	*current;

	current = stack_b;
	while (current)
	{
		eval_min_and_set_target(current, stack_a);
		current = current->next;
	}
}
