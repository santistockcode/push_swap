/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:20:03 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/07 18:22:01 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_list(t_list *head)
{
	t_list		*current;
	t_number	*number;

	current = head;
	while (current != NULL)
	{
		number = (t_number *)current->content;
		ft_printf("Value: %d, Index: %d\n", number->value, number->index);
		current = current->next;
	}
}
