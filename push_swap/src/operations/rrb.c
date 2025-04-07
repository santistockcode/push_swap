/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:45:46 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/07 17:45:49 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_rrb(t_list	*b_head)
{
	t_list	*temp;
	void	*paso;
	void	*st;
	t_list	*start;

	temp = b_head;
	start = b_head;
	st = temp->content;
	paso = temp->next->content;
	temp->next->content = st;
	temp = temp->next;
	while (temp->next)
	{
		st = temp->next->content;
		temp->next->content = paso;
		paso = st;
		temp = temp->next;
	}
	start->content = paso;
}

void	rrb(t_stacks *stacks)
{
	t_list	*b_head;

	b_head = stacks->b_head;
	if (b_head == NULL || b_head->next == NULL)
		return ;
	else
	{
		move_rrb (b_head);
	}
	write (1, "rrb\n", 4);
}
