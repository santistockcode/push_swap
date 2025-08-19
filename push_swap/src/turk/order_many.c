/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_many.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:49:14 by saalarco          #+#    #+#             */
/*   Updated: 2025/05/01 11:12:40 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/push_swap.h"

void	order_many(t_stacks *stacks)
{
	push_from_a_to_b(stacks);
	order_three(stacks);
	push_from_b_to_a(stacks);
	update_indexes(stacks->a_head);
	rotate_stack_a_min_to_top(stacks);
}
