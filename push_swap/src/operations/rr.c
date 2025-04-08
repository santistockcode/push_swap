/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:45:46 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/07 17:45:49 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rb_no_print(t_stacks *stacks)
{
	t_list	*b_head;
	t_list	*temp;

	b_head = stacks->b_head;
	if (b_head == NULL || b_head->next == NULL)
		return ;
	else
	{
		temp = b_head;
		stacks->b_head = temp;
		while (temp->next)
		{
			ft_swap (temp, temp->next);
			temp = temp->next;
		}
	}
}

void	ra_no_print(t_stacks *stacks)
{
	t_list	*a_head;
	t_list	*temp;

	a_head = stacks->a_head;
	if (a_head == NULL || a_head->next == NULL)
		return ;
	else
	{
		temp = a_head;
		stacks->a_head = temp;
		while (temp->next)
		{
			ft_swap (temp, temp->next);
			temp = temp->next;
		}
	}
}

void	rr(t_stacks *stacks)
{
	t_list	*a_head;
	t_list	*b_head;

	a_head = stacks->a_head;
	b_head = stacks->b_head;
	if (a_head == NULL || a_head->next == NULL
		|| b_head == NULL || b_head->next == NULL)
		;
	else
	{
		ra_no_print(stacks);
		rb_no_print(stacks);
		write(1, "rr\n", 3);
	}
}
