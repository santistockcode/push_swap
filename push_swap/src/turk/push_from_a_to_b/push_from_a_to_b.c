/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:54:34 by saalarco          #+#    #+#             */
/*   Updated: 2025/05/01 10:18:09 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../include/push_swap.h"

void	push_from_a_to_b(t_stacks *st)
{
	pb(st);
	pb(st);
	while (ft_lstsize(st->a_head) > 3)
	{
		update_indexes(st->a_head);
		update_indexes(st->b_head);
		set_target_a(st->a_head, st->b_head);
		calculate_price(st->a_head, st->b_head);
		mark_cheapest(st->a_head);
		do_cheapest_move_a_to_b(st);
	}
}

// printf("pushed from A to B\n");
// printf("---------------------------------A\n");
// print_list(st->a_head);
// printf("---------------------------------B\n");
// print_list(st->b_head);
// printf("END\n");