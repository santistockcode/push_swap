/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:45:46 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/07 17:45:49 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_rra(t_list *a_head)
{
	t_list	*temp;
	void	*paso;
	void	*st;
	t_list	*start;

	temp = a_head;
	start = a_head;
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

void	rra(t_stacks *stacks)
{
	t_list	*a_head;

	a_head = stacks->a_head;
	if (a_head == NULL || a_head->next == NULL)
		return ;
	else
	{
		move_rra(a_head);
	}
	write(1, "rra\n", 4);
}
