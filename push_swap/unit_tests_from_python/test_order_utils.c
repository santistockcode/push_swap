/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_order_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 00:00:00 by saalarco          #+#    #+#             */
/*   Updated: 2025/11/13 00:00:00 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <stdlib.h>
#include "../include/push_swap.h"

/*
** Helper Functions
*/

// Create a t_number node with given value
t_number *create_number(int value)
{
	t_number *num;

	num = (t_number *)malloc(sizeof(t_number));
	if (!num)
		return (NULL);
	num->value = value;
	num->index = 0;
	num->is_upper_half = 0;
	num->target_node = NULL;
	num->price_a = 0;
	num->price_b = 0;
	num->total_price = 0;
	num->is_cheapest = 0;
	return (num);
}

// Create a stack from an array of integers
t_list *create_stack(int *values, int count)
{
	t_list *head;
	t_list *node;
	t_number *num;
	int i;

	head = NULL;
	i = 0;
	while (i < count)
	{
		num = create_number(values[i]);
		node = ft_lstnew(num);
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}

// Free entire stack
void free_stack(t_list *head)
{
	ft_lstclear(&head, free);
}

/*
** Test Suite: order_utils
*/

TestSuite(order_utils);

/*
** Tests for is_ordered()
*/

Test(order_utils, is_ordered_empty_list)
{
	t_list *stack = NULL;
	
	cr_assert_eq(is_ordered(stack), 1, 
		"Empty list should be considered ordered");
}

Test(order_utils, is_ordered_single_element)
{
	int values[] = {42};
	t_list *stack = create_stack(values, 1);
	
	cr_assert_eq(is_ordered(stack), 1, 
		"Single element should be ordered");
	
	free_stack(stack);
}

Test(order_utils, is_ordered_two_ascending)
{
	int values[] = {1, 2};
	t_list *stack = create_stack(values, 2);
	
	cr_assert_eq(is_ordered(stack), 1, 
		"[1, 2] should be ordered");
	
	free_stack(stack);
}

Test(order_utils, is_ordered_two_descending)
{
	int values[] = {2, 1};
	t_list *stack = create_stack(values, 2);
	
	cr_assert_eq(is_ordered(stack), 0, 
		"[2, 1] should NOT be ordered");
	
	free_stack(stack);
}

Test(order_utils, is_ordered_multiple_ascending)
{
	int values[] = {1, 2, 3, 4, 5};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(is_ordered(stack), 1, 
		"[1, 2, 3, 4, 5] should be ordered");
	
	free_stack(stack);
}

Test(order_utils, is_ordered_multiple_unordered)
{
	int values[] = {1, 3, 2, 4, 5};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(is_ordered(stack), 0, 
		"[1, 3, 2, 4, 5] should NOT be ordered");
	
	free_stack(stack);
}

Test(order_utils, is_ordered_negative_numbers)
{
	int values[] = {-5, -3, -1, 0, 2};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(is_ordered(stack), 1, 
		"Negative numbers in order should work");
	
	free_stack(stack);
}

Test(order_utils, is_ordered_with_duplicates)
{
	int values[] = {1, 2, 2, 3, 4};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(is_ordered(stack), 1, 
		"Equal consecutive values should be considered ordered");
	
	free_stack(stack);
}

/*
** Tests for find_min_number()
*/

Test(order_utils, find_min_empty_list)
{
	t_list *stack = NULL;
	
	cr_assert_eq(find_min_number(stack), 0, 
		"Empty list should return 0");
}

Test(order_utils, find_min_single_element)
{
	int values[] = {42};
	t_list *stack = create_stack(values, 1);
	
	cr_assert_eq(find_min_number(stack), 42, 
		"Single element should be the minimum");
	
	free_stack(stack);
}

Test(order_utils, find_min_at_beginning)
{
	int values[] = {1, 2, 3, 4, 5};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(find_min_number(stack), 1, 
		"Should find minimum at beginning");
	
	free_stack(stack);
}

Test(order_utils, find_min_at_end)
{
	int values[] = {5, 4, 3, 2, 1};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(find_min_number(stack), 1, 
		"Should find minimum at end");
	
	free_stack(stack);
}

Test(order_utils, find_min_in_middle)
{
	int values[] = {5, 3, 1, 4, 2};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(find_min_number(stack), 1, 
		"Should find minimum in middle");
	
	free_stack(stack);
}

Test(order_utils, find_min_negative)
{
	int values[] = {5, -10, 0, 3, -5};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(find_min_number(stack), -10, 
		"Should find negative minimum");
	
	free_stack(stack);
}

/*
** Tests for find_max_number()
*/

Test(order_utils, find_max_empty_list)
{
	t_list *stack = NULL;
	
	cr_assert_eq(find_max_number(stack), 0, 
		"Empty list should return 0");
}

Test(order_utils, find_max_single_element)
{
	int values[] = {42};
	t_list *stack = create_stack(values, 1);
	
	cr_assert_eq(find_max_number(stack), 42, 
		"Single element should be the maximum");
	
	free_stack(stack);
}

Test(order_utils, find_max_at_beginning)
{
	int values[] = {5, 4, 3, 2, 1};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(find_max_number(stack), 5, 
		"Should find maximum at beginning");
	
	free_stack(stack);
}

Test(order_utils, find_max_at_end)
{
	int values[] = {1, 2, 3, 4, 5};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(find_max_number(stack), 5, 
		"Should find maximum at end");
	
	free_stack(stack);
}

Test(order_utils, find_max_negative)
{
	int values[] = {-5, -10, -1, -20, -3};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(find_max_number(stack), -1, 
		"Should find maximum among negatives");
	
	free_stack(stack);
}

/*
** Tests for find_index_of()
*/

Test(order_utils, find_index_of_empty_list)
{
	t_list *stack = NULL;
	
	cr_assert_eq(find_index_of(stack, 42), -1, 
		"Should return -1 for empty list");
}

Test(order_utils, find_index_of_first_element)
{
	int values[] = {10, 20, 30, 40, 50};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(find_index_of(stack, 10), 0, 
		"First element should be at index 0");
	
	free_stack(stack);
}

Test(order_utils, find_index_of_last_element)
{
	int values[] = {10, 20, 30, 40, 50};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(find_index_of(stack, 50), 4, 
		"Last element should be at index 4");
	
	free_stack(stack);
}

Test(order_utils, find_index_of_middle_element)
{
	int values[] = {10, 20, 30, 40, 50};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(find_index_of(stack, 30), 2, 
		"Middle element should be at index 2");
	
	free_stack(stack);
}

Test(order_utils, find_index_of_not_found)
{
	int values[] = {10, 20, 30, 40, 50};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(find_index_of(stack, 99), -1, 
		"Non-existent element should return -1");
	
	free_stack(stack);
}

Test(order_utils, find_index_of_negative)
{
	int values[] = {-50, -40, -30, -20, -10};
	t_list *stack = create_stack(values, 5);
	
	cr_assert_eq(find_index_of(stack, -30), 2, 
		"Should find negative numbers");
	
	free_stack(stack);
}

/*
** Tests for update_indexes()
*/

Test(order_utils, update_indexes_empty_list)
{
	t_list *stack = NULL;
	
	// Should not crash
	update_indexes(stack);
	
	cr_assert(1, "Should handle empty list without crash");
}

Test(order_utils, update_indexes_single_element)
{
	int values[] = {42};
	t_list *stack = create_stack(values, 1);
	t_number *num;
	
	update_indexes(stack);
	
	num = (t_number *)stack->content;
	cr_assert_eq(num->index, 0, "Single element should have index 0");
	cr_assert_eq(num->is_upper_half, 1, "Single element should be upper half");
	
	free_stack(stack);
}

Test(order_utils, update_indexes_multiple_elements)
{
	int values[] = {10, 20, 30, 40, 50};
	t_list *stack = create_stack(values, 5);
	t_list *current;
	t_number *num;
	int i;
	
	update_indexes(stack);
	
	current = stack;
	i = 0;
	while (current)
	{
		num = (t_number *)current->content;
		cr_assert_eq(num->index, i, 
			"Element %d should have index %d", num->value, i);
		current = current->next;
		i++;
	}
	
	free_stack(stack);
}

Test(order_utils, update_indexes_upper_half_detection)
{
	int values[] = {1, 2, 3, 4, 5};
	t_list *stack = create_stack(values, 5);
	t_number *num;
	
	update_indexes(stack);
	
	// Size = 5, so upper half is indexes 0, 1, 2 (size/2 = 2)
	num = (t_number *)stack->content;
	cr_assert_eq(num->is_upper_half, 1, "Index 0 should be upper half");
	
	num = (t_number *)stack->next->content;
	cr_assert_eq(num->is_upper_half, 1, "Index 1 should be upper half");
	
	num = (t_number *)stack->next->next->content;
	cr_assert_eq(num->is_upper_half, 1, "Index 2 should be upper half");
	
	num = (t_number *)stack->next->next->next->content;
	cr_assert_eq(num->is_upper_half, 0, "Index 3 should NOT be upper half");
	
	num = (t_number *)stack->next->next->next->next->content;
	cr_assert_eq(num->is_upper_half, 0, "Index 4 should NOT be upper half");
	
	free_stack(stack);
}

Test(order_utils, update_indexes_even_size)
{
	int values[] = {1, 2, 3, 4};
	t_list *stack = create_stack(values, 4);
	t_number *num;
	
	update_indexes(stack);
	
	// Size = 4, so upper half is indexes 0, 1 (size/2 = 2)
	num = (t_number *)stack->content;
	cr_assert_eq(num->is_upper_half, 1, "Index 0 should be upper half");
	
	num = (t_number *)stack->next->content;
	cr_assert_eq(num->is_upper_half, 1, "Index 1 should be upper half");
	
	num = (t_number *)stack->next->next->content;
	cr_assert_eq(num->is_upper_half, 0, "Index 2 should NOT be upper half");
	
	num = (t_number *)stack->next->next->next->content;
	cr_assert_eq(num->is_upper_half, 0, "Index 3 should NOT be upper half");
	
	free_stack(stack);
}

