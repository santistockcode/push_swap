/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:54:09 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/14 17:54:42 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	order_a(t_list *a_head)
{
	t_stacks	*stacks;
	int			size;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return ;
	stacks->a_head = a_head;
	stacks->b_head = NULL;
	size = ft_lstsize(a_head);
	update_indexes(stacks->a_head);
	if (size == 2)
		sa(stacks);
	else if (size == 3)
		order_three(stacks);
	else if (size <= 5)
		order_five(stacks);
	else
		order_many(stacks);
	free(stacks);
}
