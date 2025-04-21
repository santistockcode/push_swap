/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:24:48 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/21 09:27:54 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// entry point
void order_many(t_stacks *stacks);

/**
 * Push everything except 3 elements from stack_a to stack_b.
 */
void    push_from_a_to_b(t_list **stack_a, t_list **stack_b);


/**
 * For each node in `stack_a`, compute:
 *   - The 'target_value' it should be placed above in `stack_b`.
 *   - In case is already the minimun target would be the max value in b
 *   - Stor t_list from b in struct
 */
void    set_target_a(t_list *stack_a, t_list *stack_b);

/**
 * For each node in `stack_a`, compute how many moves it would take
 * to bring it to its target position in stack_b. (here we play with index + is_upper_half)
 * Case when number is right upper half in a and right down half in b that would benefit
 * from rrr or rr are not contemplated, we only measure up or down half.
 * Store that in `node->price`.
 */
void    calculate_price(t_list *stack_a, t_list *stack_b);

// mark     int is_cheapest;
void    mark_cheapest(t_list *stack);

// From info index + is_upper_half + is_cheapest
void    do_cheapest_move_a_to_b(t_list **stack_a, t_list **stack_b);

// order three

/**
 * Push everything back from stack_b to stack_a.
 */
void    push_from_b_to_a(t_list **stack_a, t_list **stack_b);

/**
 * For each node in `stack_b`, compute:
 *   - The 'target_value' it should be placed above in `stack_a`.
 *   - In case is already the max target would be the min value in b
 *   - Stor t_list from a in struct
 */
void    set_target_b(t_list *stack_a, t_list *stack_b);

// reuse calculate price from when pushing a to b

// reuse mark cheapest

// From info index + is_upper_half + is_cheapest
void    do_cheapest_move_b_to_a(t_list **stack_a, t_list **stack_b);

// finally
void    rotate_stack_a_min_to_top(t_list **stack_a);

// check if already ordered
