/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:24:54 by saalarco          #+#    #+#             */
/*   Updated: 2025/05/01 11:22:38 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// function that order a (if 5 or less calls order_few)
void	order_a(t_list *a_head);

// function that checks if the stack is ordered
int		is_ordered(t_list *a_head);

// function that returns min number in the stack
int		find_min_number(t_list *a_head);

// function that returns max number in the stack. 
int		find_max_number(t_list *a_head);

// function to update the indexes of the stack and set is_upper_half
void	update_indexes(t_list *a_head);

// function to find index of x number (even if indexes are not updated)
int		find_index_of(t_list *a_head, int number);
