/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:45:46 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/07 17:45:49 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sb(t_stacks *stacks)
{
	t_list	*a_head;

	a_head = stacks->b_head;
	if (a_head == NULL || a_head->next == NULL)
		return ;
	ft_swap(a_head, a_head->next);
	write(1, "sb\n", 3);
}
