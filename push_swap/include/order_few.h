/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_few.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:24:57 by saalarco          #+#    #+#             */
/*   Updated: 2025/05/01 11:18:42 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this function orders a list of three elements
void	order_three(t_stacks *stacks);

// this function orders a list of 5 or less elements
void	order_five(t_stacks *stacks);

// Pushes the minimum element from a to b
void	push_min_to_b(t_stacks *stacks);
