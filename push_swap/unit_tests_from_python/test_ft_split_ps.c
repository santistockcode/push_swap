/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 00:00:00 by saalarco          #+#    #+#             */
/*   Updated: 2025/11/13 00:00:00 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../include/push_swap.h"

/*
** NOTE: ft_split_ps uses a static variable (cursor) in alloc_word().
** This means it can only be called ONCE per program execution.
** 
** In push_swap, this is fine because:
** - The function is called once to parse arguments
** - The program exits immediately after
** - The static variable resets when the process ends
**
** For testing, we use Criterion's fork mode (default) where each test
** runs in a separate process, so the static variable resets between tests.
*/

// Helper function to free the result of ft_split_ps
static void free_split(char **split)
{
	int i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Helper function to count elements in split result
static int count_elements(char **split)
{
	int count;

	count = 0;
	if (!split)
		return (0);
	while (split[count])
		count++;
	return (count);
}

/*
** Test Suite: ft_split_ps
** Each test runs in a separate forked process (Criterion default behavior),
** so the static variable resets between tests.
*/

TestSuite(ft_split_ps);

Test(ft_split_ps, simple_single_word)
{
	char **result = ft_split_ps("42");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 1, "Should have 1 element");
	cr_assert_str_eq(result[0], "42", "First element should be '42'");
	cr_assert_null(result[1], "Second element should be NULL sentinel");
	
	free_split(result);
}

Test(ft_split_ps, multiple_words_single_space)
{
	char **result = ft_split_ps("1 2 3 4 5");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 5, "Should have 5 elements");
	cr_assert_str_eq(result[0], "1", "First element should be '1'");
	cr_assert_str_eq(result[1], "2", "Second element should be '2'");
	cr_assert_str_eq(result[2], "3", "Third element should be '3'");
	cr_assert_str_eq(result[3], "4", "Fourth element should be '4'");
	cr_assert_str_eq(result[4], "5", "Fifth element should be '5'");
	cr_assert_null(result[5], "Should have NULL sentinel");
	
	free_split(result);
}

Test(ft_split_ps, multiple_spaces_between_words)
{
	char **result = ft_split_ps("1    2     3");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 3, "Should have 3 elements");
	cr_assert_str_eq(result[0], "1", "First element should be '1'");
	cr_assert_str_eq(result[1], "2", "Second element should be '2'");
	cr_assert_str_eq(result[2], "3", "Third element should be '3'");
	
	free_split(result);
}

Test(ft_split_ps, leading_spaces)
{
	char **result = ft_split_ps("   1 2 3");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 3, "Should have 3 elements");
	cr_assert_str_eq(result[0], "1", "First element should be '1'");
	cr_assert_str_eq(result[1], "2", "Second element should be '2'");
	cr_assert_str_eq(result[2], "3", "Third element should be '3'");
	
	free_split(result);
}

Test(ft_split_ps, trailing_spaces)
{
	char **result = ft_split_ps("1 2 3   ");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 3, "Should have 3 elements");
	cr_assert_str_eq(result[0], "1", "First element should be '1'");
	cr_assert_str_eq(result[1], "2", "Second element should be '2'");
	cr_assert_str_eq(result[2], "3", "Third element should be '3'");
	
	free_split(result);
}

Test(ft_split_ps, tabs_and_spaces)
{
	char **result = ft_split_ps("1\t2   3\t\t4");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 4, "Should have 4 elements");
	cr_assert_str_eq(result[0], "1", "First element should be '1'");
	cr_assert_str_eq(result[1], "2", "Second element should be '2'");
	cr_assert_str_eq(result[2], "3", "Third element should be '3'");
	cr_assert_str_eq(result[3], "4", "Fourth element should be '4'");
	
	free_split(result);
}

Test(ft_split_ps, newlines_and_mixed_whitespace)
{
	char **result = ft_split_ps("1\n2\r\n3  \t 4");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 4, "Should have 4 elements");
	cr_assert_str_eq(result[0], "1", "First element should be '1'");
	cr_assert_str_eq(result[1], "2", "Second element should be '2'");
	cr_assert_str_eq(result[2], "3", "Third element should be '3'");
	cr_assert_str_eq(result[3], "4", "Fourth element should be '4'");
	
	free_split(result);
}

Test(ft_split_ps, empty_string)
{
	char **result = ft_split_ps("");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 0, "Should have 0 elements");
	cr_assert_null(result[0], "First element should be NULL sentinel");
	
	free_split(result);
}

Test(ft_split_ps, only_whitespace)
{
	char **result = ft_split_ps("   \t\n  ");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 0, "Should have 0 elements");
	cr_assert_null(result[0], "First element should be NULL sentinel");
	
	free_split(result);
}

Test(ft_split_ps, negative_numbers)
{
	char **result = ft_split_ps("-42 -100 -1");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 3, "Should have 3 elements");
	cr_assert_str_eq(result[0], "-42", "First element should be '-42'");
	cr_assert_str_eq(result[1], "-100", "Second element should be '-100'");
	cr_assert_str_eq(result[2], "-1", "Third element should be '-1'");
	
	free_split(result);
}

Test(ft_split_ps, large_numbers)
{
	char **result = ft_split_ps("2147483647 -2147483648");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 2, "Should have 2 elements");
	cr_assert_str_eq(result[0], "2147483647", "First element should be INT_MAX");
	cr_assert_str_eq(result[1], "-2147483648", "Second element should be INT_MIN");
	
	free_split(result);
}

Test(ft_split_ps, complex_whitespace_pattern)
{
	char **result = ft_split_ps("  \t 1 \n\n 2   \t\t 3 \r\n 4  ");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 4, "Should have 4 elements");
	cr_assert_str_eq(result[0], "1");
	cr_assert_str_eq(result[1], "2");
	cr_assert_str_eq(result[2], "3");
	cr_assert_str_eq(result[3], "4");
	
	free_split(result);
}

Test(ft_split_ps, many_numbers)
{
	char **result = ft_split_ps("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 15, "Should have 15 elements");
	
	// Spot check a few
	cr_assert_str_eq(result[0], "1");
	cr_assert_str_eq(result[7], "8");
	cr_assert_str_eq(result[14], "15");
	
	free_split(result);
}

Test(ft_split_ps, real_world_example)
{
	// Simulates actual push_swap usage
	char **result = ft_split_ps("5 2 8 1 9 3 7 4 6");
	
	cr_assert_not_null(result, "Result should not be NULL");
	cr_assert_eq(count_elements(result), 9, "Should have 9 elements");
	
	// Verify all elements
	cr_assert_str_eq(result[0], "5");
	cr_assert_str_eq(result[1], "2");
	cr_assert_str_eq(result[2], "8");
	cr_assert_str_eq(result[3], "1");
	cr_assert_str_eq(result[4], "9");
	cr_assert_str_eq(result[5], "3");
	cr_assert_str_eq(result[6], "7");
	cr_assert_str_eq(result[7], "4");
	cr_assert_str_eq(result[8], "6");
	
	free_split(result);
}
