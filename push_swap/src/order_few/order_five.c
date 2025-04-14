/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:50:23 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/14 17:51:37 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/push_swap.h"

void	order_five(t_stacks *stacks)
{
	int	flag_5;

	flag_5 = 0;
	push_min_to_b(stacks);
	if (ft_lstsize(stacks->a_head) == 4)
	{
		flag_5 = 1;
		push_min_to_b(stacks);
	}
	order_three(stacks);
	pa(stacks);
	if (flag_5)
		pa(stacks);
}
