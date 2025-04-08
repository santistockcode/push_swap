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
	t_list	*current;
	void	*grab_content;
	void	*temp_content;

	current = a_head;
	while (current->next)
	{
		current = current->next;
	}
	grab_content = current->content;
	current = a_head;
	while (current)
	{
		temp_content = current->content;
		current->content = grab_content;
		grab_content = temp_content;
		current = current->next;
	}
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
