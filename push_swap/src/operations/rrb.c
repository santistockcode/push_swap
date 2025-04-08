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
	t_list	*current;
	void	*grab_content;
	void	*temp_content;

	current = b_head;
	while (current->next)
	{
		current = current->next;
	}
	grab_content = current->content;
	current = b_head;
	while (current)
	{
		temp_content = current->content;
		current->content = grab_content;
		grab_content = temp_content;
		current = current->next;
	}
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
