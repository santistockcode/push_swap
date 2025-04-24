/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:11:02 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/24 18:51:42 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/push_swap.h"

void	mark_node_at(t_list *stack, int index)
{
	t_list		*current;
	int			counter;
	t_number	*nbr;

	counter = 0;
	current = stack;
	while (current)
	{
		nbr = (t_number *)current->content;
		if (counter == index)
			nbr->is_cheapest = 1;
		counter++;
		current = current->next;
	}
}

/*
stores min value of total_price and its index
*/
void	mark_cheapest(t_list *stack)
{
	t_list		*current;
	int			min;
	int			index;
	t_number	*nbr;
	int			counter;

	index = 0;
	counter = 0;
	current = stack;
	nbr = (t_number *) current->content;
	min = nbr->total_price;
	while (current)
	{
		nbr = (t_number *)current->content;
		nbr->is_cheapest = 0;
		if (nbr->total_price < min)
		{
			min = nbr->total_price;
			index = counter;
		}
		current = current->next;
		counter++;
	}
	mark_node_at(stack, index);
}
