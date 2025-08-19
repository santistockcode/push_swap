/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cheapest_move_a_to_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:54:11 by saalarco          #+#    #+#             */
/*   Updated: 2025/05/01 10:24:46 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../include/push_swap.h"

t_list	*find_cheapest_node(t_list *stack_a)
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

void	rr_ra_rb(t_stacks *st, int price_a, int price_b)
{
	if (price_a >= price_b)
	{
		while (price_a-- > price_b)
			ra(st);
		while (price_b-- > 0)
			rr(st);
	}
	else if (price_a <= price_b)
	{
		while (price_b-- > price_a)
			rb(st);
		while (price_a-- > 0)
			rr(st);
	}
	pb(st);
}

void	rrr_rra_rrb(t_stacks *st, int price_a, int price_b)
{
	if (price_a <= price_b)
	{
		while (price_a++ < price_b)
			rra(st);
		while (price_b++ < 0)
			rrr(st);
	}
	else if (price_a >= price_b)
	{
		while (price_b++ < price_a)
			rrb(st);
		while (price_a++ < 0)
			rrr(st);
	}
	pb(st);
}

void	optimus_case_scenario(t_stacks *st, int price_a, int price_b)
{
	if (price_a >= 0 && price_b >= 0)
	{
		rr_ra_rb(st, price_a, price_b);
		return ;
	}
	else if (price_a <= 0 && price_b <= 0)
	{
		rrr_rra_rrb(st, price_a, price_b);
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
void	do_cheapest_move_a_to_b(t_stacks *st)
{
	t_list	*cheapest_node;
	int		price_a;
	int		price_b;

	cheapest_node = find_cheapest_node(st->a_head);
	price_a = ((t_number *)cheapest_node->content)->price_a;
	price_b = ((t_number *)cheapest_node->content)->price_b;
	if ((price_a >= 0 && price_b >= 0) || (price_a <= 0 && price_b <= 0))
		optimus_case_scenario(st, price_a, price_b);
	else if (price_a > 0 && price_b < 0)
	{
		while (price_a-- > 0)
			ra(st);
		while (price_b++ < 0)
			rrb(st);
		pb(st);
	}
	else if (price_a < 0 && price_b > 0)
	{
		while (price_a++ < 0)
			rra(st);
		while (price_b-- > 0)
			rb(st);
		pb(st);
	}
}
