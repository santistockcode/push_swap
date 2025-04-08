/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:45:46 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/07 17:45:49 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stacks *stacks)
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
			ft_swap(temp, temp->next);
			temp = temp->next;
		}
	}
	write(1, "ra\n", 3);
}
