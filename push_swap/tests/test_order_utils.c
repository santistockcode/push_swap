#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "./../include/push_swap.h"

void test_find_index_of()
{
    // test0
    t_list *head_a;
    head_a = NULL;

    t_number *number_1 = (t_number *)malloc(sizeof(t_number));
    number_1->value = 1;
    t_list *new_node_1 = ft_lstnew(number_1);
    ft_lstadd_back(&head_a, new_node_1);

    t_number *number_2 = (t_number *)malloc(sizeof(t_number));
    number_2->value = 2;
    t_list *new_node_2 = ft_lstnew(number_2);
    ft_lstadd_back(&head_a, new_node_2);

    t_number *number_3 = (t_number *)malloc(sizeof(t_number));
    number_3->value = 3;
    t_list *new_node_3 = ft_lstnew(number_3);
    ft_lstadd_back(&head_a, new_node_3);

    int index = find_index_of(head_a, 2);
    assert(index == 1);

    index = find_index_of(head_a, 4);
    assert(index == -1);

    ft_lstclear(&head_a, free);

    // test1
    t_list *head_a1;
    head_a1 = NULL;

    int index1 = find_index_of(head_a1, 2);
    assert(index1 == -1);

    ft_lstclear(&head_a1, free);

    index1 = find_index_of(head_a1, 4);
    assert(index1 == -1);
}

/*
typedef struct s_number
{
    int	value;
    int	index;
    int is_upper_half;
}	t_number;*/
void test_update_indexes()
{
    // test0 (indexes not set yet)
    t_list *head_a;
    head_a = NULL;

    t_number *number_1 = (t_number *)malloc(sizeof(t_number));
    number_1->value = 1;
    t_list *new_node_1 = ft_lstnew(number_1);
    ft_lstadd_back(&head_a, new_node_1);

    t_number *number_2 = (t_number *)malloc(sizeof(t_number));
    number_2->value = 2;
    t_list *new_node_2 = ft_lstnew(number_2);
    ft_lstadd_back(&head_a, new_node_2);

    t_number *number_3 = (t_number *)malloc(sizeof(t_number));
    number_3->value = 3;
    t_list *new_node_3 = ft_lstnew(number_3);
    ft_lstadd_back(&head_a, new_node_3);

    update_indexes(head_a);

    assert(((t_number *)head_a->content)->index == 0);
    assert(((t_number *)head_a->next->content)->index == 1);
    assert(((t_number *)head_a->next->next->content)->index == 2);

    ft_lstclear(&head_a, free);

    // test1 (indexes already set but a la virulé)
    t_list *head_a1;
    head_a1 = NULL;

    t_number *number_4 = (t_number *)malloc(sizeof(t_number));
    number_4->value = 1;
    number_4->index = 5;
    number_4->is_upper_half = 0;
    t_list *new_node_4 = ft_lstnew(number_4);
    ft_lstadd_back(&head_a1, new_node_4);

    t_number *number_5 = (t_number *)malloc(sizeof(t_number));
    number_5->value = 2;
    number_5->index = 10;
    number_5->is_upper_half = 0;
    t_list *new_node_5 = ft_lstnew(number_5);
    ft_lstadd_back(&head_a1, new_node_5);

    t_number *number_6 = (t_number *)malloc(sizeof(t_number));
    number_6->value = 3;
    number_6->index = 2;
    number_6->is_upper_half = 1;
    t_list *new_node_6 = ft_lstnew(number_6);
    ft_lstadd_back(&head_a1, new_node_6);

    update_indexes(head_a1);
    assert(((t_number *)head_a1->content)->index == 0);
    assert(((t_number *)head_a1->next->content)->index == 1);
    assert(((t_number *)head_a1->next->next->content)->index == 2);
    assert(((t_number *)head_a1->content)->is_upper_half == 1);
    assert(((t_number *)head_a1->next->content)->is_upper_half == 1);
    assert(((t_number *)head_a1->next->next->content)->is_upper_half == 0);
    
    ft_lstclear(&head_a1, free);

    // test2 (indexes correct but apply pa and then update_indexes)
    t_list *head_a2;
    t_list  *head_b;
    head_a2 = NULL;
    head_b = NULL;
    t_stacks    *stacks;
    stacks = (t_stacks *)malloc(sizeof(t_stacks));
    if (!stacks)
        return;

    t_number *number_7 = (t_number *)malloc(sizeof(t_number));
    number_7->value = 1;
    number_7->index = 0;
    number_7->is_upper_half = 1;
    t_list *new_node_7 = ft_lstnew(number_7);
    ft_lstadd_back(&head_a2, new_node_7);

    t_number *number_8 = (t_number *)malloc(sizeof(t_number));
    number_8->value = 2;
    number_8->index = 1;
    number_8->is_upper_half = 1;
    t_list *new_node_8 = ft_lstnew(number_8);
    ft_lstadd_back(&head_a2, new_node_8);

    t_number *number_9 = (t_number *)malloc(sizeof(t_number));
    number_9->value = 3;
    number_9->index = 2;
    number_9->is_upper_half = 0;
    t_list *new_node_9 = ft_lstnew(number_9);
    ft_lstadd_back(&head_a2, new_node_9);

    stacks->a_head = head_a2;
    stacks->b_head = head_b;

    sa(stacks);
    assert(((t_number *)stacks->a_head->content)->index == 1);
    assert(((t_number *)stacks->a_head->next->content)->index == 0);
    assert(((t_number *)stacks->a_head->next->next->content)->index == 2);
    assert(((t_number *)stacks->a_head->content)->is_upper_half == 1);
    assert(((t_number *)stacks->a_head->next->content)->is_upper_half == 1);
    assert(((t_number *)stacks->a_head->next->next->content)->is_upper_half == 0);
    update_indexes(stacks->a_head);
    assert(((t_number *)stacks->a_head->content)->index == 0);
    assert(((t_number *)stacks->a_head->next->content)->index == 1);
    assert(((t_number *)stacks->a_head->next->next->content)->index == 2);
    assert(((t_number *)stacks->a_head->content)->is_upper_half == 1);
    assert(((t_number *)stacks->a_head->next->content)->is_upper_half == 1);
    assert(((t_number *)stacks->a_head->next->next->content)->is_upper_half == 0);
    ra(stacks);
    assert(((t_number *)stacks->a_head->content)->index == 1);
    assert(((t_number *)stacks->a_head->next->content)->index == 2);
    assert(((t_number *)stacks->a_head->next->next->content)->index == 0);
    assert(((t_number *)stacks->a_head->content)->is_upper_half == 1);
    assert(((t_number *)stacks->a_head->next->content)->is_upper_half == 0);
    assert(((t_number *)stacks->a_head->next->next->content)->is_upper_half == 1);
    update_indexes(stacks->a_head);
    assert(((t_number *)stacks->a_head->content)->index == 0);
    assert(((t_number *)stacks->a_head->next->content)->index == 1);
    assert(((t_number *)stacks->a_head->next->next->content)->index == 2);
    assert(((t_number *)stacks->a_head->content)->is_upper_half == 1);
    assert(((t_number *)stacks->a_head->next->content)->is_upper_half == 1);
    assert(((t_number *)stacks->a_head->next->next->content)->is_upper_half == 0);

    ft_lstclear(&stacks->a_head, free);
    free(stacks);
}

void test_is_ordered()
{
    // test0
    t_list *head_a;
    head_a = NULL;

    t_number *number_1 = (t_number *)malloc(sizeof(t_number));
    number_1->value = 1;
    t_list *new_node_1 = ft_lstnew(number_1);
    ft_lstadd_back(&head_a, new_node_1);

    t_number *number_2 = (t_number *)malloc(sizeof(t_number));
    number_2->value = 2;
    t_list *new_node_2 = ft_lstnew(number_2);
    ft_lstadd_back(&head_a, new_node_2);

    t_number *number_3 = (t_number *)malloc(sizeof(t_number));
    number_3->value = 3;
    t_list *new_node_3 = ft_lstnew(number_3);
    ft_lstadd_back(&head_a, new_node_3);

    int result = is_ordered(head_a);
    assert(result == 1);

    ft_lstclear(&head_a, free);

    // test1
    t_list *head_a1;
    head_a1 = NULL;

    t_number *number_4 = (t_number *)malloc(sizeof(t_number));
    number_4->value = 3;
    t_list *new_node_4 = ft_lstnew(number_4);
    ft_lstadd_back(&head_a1, new_node_4);

    t_number *number_5 = (t_number *)malloc(sizeof(t_number));
    number_5->value = 2;
    t_list *new_node_5 = ft_lstnew(number_5);
    ft_lstadd_back(&head_a1, new_node_5);

    t_number *number_6 = (t_number *)malloc(sizeof(t_number));
    number_6->value = 1;
    t_list *new_node_6 = ft_lstnew(number_6);
    ft_lstadd_back(&head_a1, new_node_6);

    result = is_ordered(head_a1);
    assert(result == 0);

    ft_lstclear(&head_a1, free);
}

void test_find_min_number()
{
    // test0
    t_list *head_a;
    head_a = NULL;

    t_number *number_1 = (t_number *)malloc(sizeof(t_number));
    number_1->value = 1;
    t_list *new_node_1 = ft_lstnew(number_1);
    ft_lstadd_back(&head_a, new_node_1);

    t_number *number_2 = (t_number *)malloc(sizeof(t_number));
    number_2->value = 2;
    t_list *new_node_2 = ft_lstnew(number_2);
    ft_lstadd_back(&head_a, new_node_2);

    t_number *number_3 = (t_number *)malloc(sizeof(t_number));
    number_3->value = 3;
    t_list *new_node_3 = ft_lstnew(number_3);
    ft_lstadd_back(&head_a, new_node_3);

    int min_value = find_min_number(head_a);
    assert(min_value == 1);

    ft_lstclear(&head_a, free);
}

void test_find_max_number()
{
    // test0
    t_list *head_a;
    head_a = NULL;

    t_number *number_1 = (t_number *)malloc(sizeof(t_number));
    number_1->value = 1;
    t_list *new_node_1 = ft_lstnew(number_1);
    ft_lstadd_back(&head_a, new_node_1);

    t_number *number_2 = (t_number *)malloc(sizeof(t_number));
    number_2->value = 2;
    t_list *new_node_2 = ft_lstnew(number_2);
    ft_lstadd_back(&head_a, new_node_2);

    t_number *number_3 = (t_number *)malloc(sizeof(t_number));
    number_3->value = 3;
    t_list *new_node_3 = ft_lstnew(number_3);
    ft_lstadd_back(&head_a, new_node_3);

    int max_value = find_max_number(head_a);
    assert(max_value == 3);

    ft_lstclear(&head_a, free);
}

int main(void)
{
    test_find_index_of();
    test_update_indexes();
    test_is_ordered();
    test_find_min_number();
    test_find_max_number();
}