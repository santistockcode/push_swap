/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:45:46 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/07 17:45:49 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rb(t_stacks *stacks)
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
			ft_swap(temp, temp->next);
			temp = temp->next;
		}
	}
	write(1, "rb\n", 3);
}
