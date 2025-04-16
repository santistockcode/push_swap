/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:50:34 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/14 17:52:50 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/push_swap.h"

void	order_three(t_stacks *stacks)
{
	t_list	*a_head;

	a_head = stacks->a_head;
	if (is_ordered(a_head))
		return ;
	if (find_min_number(a_head) == ((t_number *)a_head->content)->value)
	{
		sa(stacks);
		ra(stacks);
		return ;
	}
	if (find_max_number(a_head) == ((t_number *)a_head->content)->value)
	{
		ra(stacks);
		if (is_ordered(a_head))
			return ;
		else
			sa(stacks);
		return ;
	}
	if (find_min_number(a_head) == ((t_number *)a_head->next->content)->value)
		sa(stacks);
	else if (find_max_number(a_head)
		== ((t_number *)a_head->next->content)->value)
		rra(stacks);
}
