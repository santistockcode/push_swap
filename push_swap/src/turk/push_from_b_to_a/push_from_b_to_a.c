/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:54:34 by saalarco          #+#    #+#             */
/*   Updated: 2025/05/01 10:55:55 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../include/push_swap.h"

void	push_from_b_to_a(t_stacks *st)
{
	while (ft_lstsize(st->b_head))
	{
		update_indexes(st->a_head);
		update_indexes(st->b_head);
		set_target_b(st->b_head, st->a_head);
		calculate_price(st->b_head, st->a_head);
		mark_cheapest(st->b_head);
		do_cheapest_move_b_to_a(st);
	}
}
