/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:36:49 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/21 12:24:25 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../include/push_swap.h"


void assign_max_target(t_list *node_a, t_list *stack_b, int index)
{
	t_list	*current;
	int	 counter;

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

void eval_max_and_set_target(t_list *node_a, t_list *stack_b)
{
	t_list	*proposal;
	int value_a;
	int value_b;
	int	max;
	int best;
		
	max = INT_MIN;
	best = INT_MIN;
	value_a = ((t_number *)node_a->content)->value;
	proposal = stack_b;
	while (proposal)
	{
		value_b = ((t_number *)proposal->content)->value;
		if (value_b < value_a && value_b > best)
		{
			((t_number *)node_a->content)->target_node = proposal;
			best = value_b;
		}
		else if (value_b > max)
			max = value_b;
		proposal = proposal->next;
	}
	if (best == INT_MIN)
		assign_max_target(node_a, stack_b, find_index_of(stack_b, max));
}
/*
target = “closest smaller value in B” 
		 (or max‑value‑in‑B if none is smaller)
*/
void    set_target_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*current;

	current = stack_a;
	while (current)
	{
		eval_max_and_set_target(current, stack_b);
		current = current->next;
	}
}
