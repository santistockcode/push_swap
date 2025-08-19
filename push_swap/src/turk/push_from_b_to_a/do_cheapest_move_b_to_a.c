/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cheapest_move_b_to_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:53:28 by saalarco          #+#    #+#             */
/*   Updated: 2025/05/01 11:16:57 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../include/push_swap.h"

t_list	*find_cheapest_node_b(t_list *stack_a)
{
	t_list	*current;

	current = stack_a;
	while (current)
	{
		if (((t_number *)current->content)->is_cheapest == 1)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	rr_ra_rb_b_to_a(t_stacks *st, int price_a, int price_b)
{
	if (price_a >= price_b)
	{
		while (price_a-- > price_b)
			rb(st);
		while (price_b-- > 0)
			rr(st);
	}
	else if (price_a <= price_b)
	{
		while (price_b-- > price_a)
			ra(st);
		while (price_a-- > 0)
			rr(st);
	}
	pa(st);
}

void	rrr_rra_rrb_b_to_a(t_stacks *st, int price_a, int price_b)
{
	if (price_a <= price_b)
	{
		while (price_a++ < price_b)
			rrb(st);
		while (price_b++ < 0)
			rrr(st);
	}
	else if (price_a >= price_b)
	{
		while (price_b++ < price_a)
			rra(st);
		while (price_a++ < 0)
			rrr(st);
	}
	pa(st);
}

void	best_case_scenario(t_stacks *st, int price_a, int price_b)
{
	if (price_a >= 0 && price_b >= 0)
	{
		rr_ra_rb_b_to_a(st, price_a, price_b);
		return ;
	}
	else if (price_a <= 0 && price_b <= 0)
	{
		rrr_rra_rrb_b_to_a(st, price_a, price_b);
		return ;
	}
}

/*
This function finds the number where is_cheapest is set to 1 in stack_a
If price_a and price_b are both positive or both negative,
it means that the cheapest 
move is to rotate/reverse rotate both stacks in the same direction,
and then rotate until both are
at the top. Then push a to b.
If price_a is positive and price_b is negative,
it means that the cheapest move is to
rotate stack_a and reverse rotate stack_b, and then push a to b.
If price_a is negative and price_b is positive,
it means that the cheapest move is to
reverse rotate stack_a and rotate stack_b, and then push a to b.
If */
void	do_cheapest_move_b_to_a(t_stacks *st)
{
	t_list	*cheapest_node;
	int		price_a;
	int		price_b;

	cheapest_node = find_cheapest_node_b(st->b_head);
	price_a = ((t_number *)cheapest_node->content)->price_a;
	price_b = ((t_number *)cheapest_node->content)->price_b;
	if ((price_a >= 0 && price_b >= 0) || (price_a <= 0 && price_b <= 0))
		best_case_scenario(st, price_a, price_b);
	else if (price_a > 0 && price_b < 0)
	{
		while (price_a-- > 0)
			rb(st);
		while (price_b++ < 0)
			rra(st);
		pa(st);
	}
	else if (price_a < 0 && price_b > 0)
	{
		while (price_a++ < 0)
			rrb(st);
		while (price_b-- > 0)
			ra(st);
		pa(st);
	}
}
