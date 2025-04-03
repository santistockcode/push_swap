// tests this lists: 
//a ""
//b 1 
//c 1 2 
//d 1 2 3
//e 1 2 3 4

// Para cada lista de las anteriores se aplica cada una de las operaciones unitarias (actuan solo sobre un stack) y se chequea el resultado final (asssert)

// Para la combinación de estas listas en a con cada una de esas listas en b se chequean las operaciones no unitarias (actuan sobre stack a y b) y se chequea el resultado final (assert)

// liberar las dos listas y la estructura con los dos stacks después de cada test

// better check the results from makefile valgrind (leaks are posible at this point still)

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "./../include/push_swap.h"

void    test_sa()
{
    t_stacks    *stacks;
    
    //  0 A EMPTY LIST
    t_list  *head_a_0;
    t_list  *head_b_0;

    stacks = (t_stacks *)malloc(sizeof(t_stacks));
    if (!stacks)
        return;
    head_a_0 = NULL;
    head_b_0 = NULL;
    t_list *new_node_a_0 = ft_lstnew(NULL);
    ft_lstadd_back(&head_a_0, new_node_a_0);
    stacks->a_head = head_a_0;
    stacks->b_head = head_b_0;

    sa(stacks);
    assert(stacks->a_head->content == NULL);
    assert(stacks->b_head == NULL);
    ft_lstclear(&head_a_0, free);
    

    // A 1 LIST WITH ONE ELEMENT B EMPTY LIST
    t_list  *head_a_1;
    t_list  *head_b_1;

    head_a_1 = NULL;
    head_b_1 = NULL;

    t_number *number_1 = (t_number *)malloc(sizeof(t_number));
    number_1->value = 1;
    t_list *new_node_a_1 = ft_lstnew(number_1);
    ft_lstadd_back(&head_a_1, new_node_a_1);
    stacks->a_head = head_a_1;
    stacks->b_head = head_b_1;

    sa(stacks);
    assert(stacks->a_head->content == number_1);
    assert(stacks->b_head == NULL);
    ft_lstclear(&head_a_1, free);

    // A 2 LIST WITH TWO ELEMENTS B EMPTY LIST
    t_list  *head_a_2;
    t_list  *head_b_2;

    head_a_2 = NULL;
    head_b_2 = NULL;
    
    t_number *number_2_1 = (t_number *)malloc(sizeof(t_number));
    number_2_1->value = 1;
    t_list *new_node_a_2_1 = ft_lstnew(number_2_1);
    ft_lstadd_back(&head_a_2, new_node_a_2_1);

    t_number *number_2_2 = (t_number *)malloc(sizeof(t_number));
    number_2_2->value = 2;
    t_list *new_node_a_2_2 = ft_lstnew(number_2_2);
    ft_lstadd_back(&head_a_2, new_node_a_2_2);
    stacks->a_head = head_a_2;
    stacks->b_head = head_b_2;
    sa(stacks);

    assert(stacks->a_head->content == number_2_2);
    assert(stacks->a_head->next->content == number_2_1);
    assert(stacks->b_head == NULL);
    ft_lstclear(&head_a_2, free);


    // A 3 LIST WITH THREE ELEMENTS B EMPTY LIST
    t_list  *head_a_3;
    t_list  *head_b_3;

    head_a_3 = NULL;
    head_b_3 = NULL;

    t_number *number_3_1 = (t_number *)malloc(sizeof(t_number));
    number_3_1->value = 1;
    t_list *new_node_a_3_1 = ft_lstnew(number_3_1);
    ft_lstadd_back(&head_a_3, new_node_a_3_1);

    t_number *number_3_2 = (t_number *)malloc(sizeof(t_number));
    number_3_2->value = 2;
    t_list *new_node_a_3_2 = ft_lstnew(number_3_2);
    ft_lstadd_back(&head_a_3, new_node_a_3_2);

    t_number *number_3_3 = (t_number *)malloc(sizeof(t_number));
    number_3_3->value = 3;
    t_list *new_node_a_3_3 = ft_lstnew(number_3_3);
    ft_lstadd_back(&head_a_3, new_node_a_3_3);

    stacks->a_head = head_a_3;
    stacks->b_head = head_b_3;
    sa(stacks);

    assert(stacks->a_head->content == number_3_2);
    assert(stacks->a_head->next->content == number_3_1);
    assert(stacks->a_head->next->next->content == number_3_3);
    assert(stacks->b_head == NULL);
    ft_lstclear(&head_a_3, free);


    // A 4 LIST WITH FOUR ELEMENTS B EMPTY LIST
    t_list  *head_a_4;
    t_list  *head_b_4;

    head_a_4 = NULL;
    head_b_4 = NULL;

    t_number *number_4_1 = (t_number *)malloc(sizeof(t_number));
    number_4_1->value = 1;
    t_list *new_node_a_4_1 = ft_lstnew(number_4_1);
    ft_lstadd_back(&head_a_4, new_node_a_4_1);

    t_number *number_4_2 = (t_number *)malloc(sizeof(t_number));
    number_4_2->value = 2;
    t_list *new_node_a_4_2 = ft_lstnew(number_4_2);
    ft_lstadd_back(&head_a_4, new_node_a_4_2);

    t_number *number_4_3 = (t_number *)malloc(sizeof(t_number));
    number_4_3->value = 3;
    t_list *new_node_a_4_3 = ft_lstnew(number_4_3);
    ft_lstadd_back(&head_a_4, new_node_a_4_3);

    t_number *number_4_4 = (t_number *)malloc(sizeof(t_number));
    number_4_4->value = 4;
    t_list *new_node_a_4_4 = ft_lstnew(number_4_4);
    ft_lstadd_back(&head_a_4, new_node_a_4_4);

    stacks->a_head = head_a_4;
    stacks->b_head = head_b_4;
    sa(stacks);

    assert(stacks->a_head->content == number_4_2);
    assert(stacks->a_head->next->content == number_4_1);
    assert(stacks->a_head->next->next->content == number_4_3);
    assert(stacks->a_head->next->next->next->content == number_4_4);
    assert(stacks->b_head == NULL);
    ft_lstclear(&head_a_4, free);

    free(stacks);

}


void test_sb()
{
    t_stacks *stacks;

    // 0 A EMPTY LIST
    t_list *head_a_0;
    t_list *head_b_0;
    stacks = (t_stacks *)malloc(sizeof(t_stacks));
    if (!stacks)
        return;
    head_a_0 = NULL;
    head_b_0 = NULL;
    t_list *new_node_b_0 = ft_lstnew(NULL);
    ft_lstadd_back(&head_b_0, new_node_b_0);
    stacks->a_head = head_a_0;
    stacks->b_head = head_b_0;
    sb(stacks);
    assert(stacks->a_head == NULL);
    assert(stacks->b_head->content == NULL);
    ft_lstclear(&head_b_0, free);

    // A EMPTY LIST B 1 LIST WITH ONE ELEMENT
    t_list *head_a_1;
    t_list *head_b_1;
    head_a_1 = NULL;
    head_b_1 = NULL;
    t_number *number_1 = (t_number *)malloc(sizeof(t_number));
    number_1->value = 1;
    t_list *new_node_b_1 = ft_lstnew(number_1);
    ft_lstadd_back(&head_b_1, new_node_b_1);
    stacks->a_head = head_a_1;
    stacks->b_head = head_b_1;
    sb(stacks);
    assert(stacks->a_head == NULL);
    assert(stacks->b_head->content == number_1);
    ft_lstclear(&head_b_1, free);

    // A EMPTY LIST B 2 LIST WITH TWO ELEMENTS
    t_list *head_a_2;
    t_list *head_b_2;
    head_a_2 = NULL;
    head_b_2 = NULL;

    t_number *number_2_1 = (t_number *)malloc(sizeof(t_number));
    number_2_1->value = 1;
    t_list *new_node_b_2_1 = ft_lstnew(number_2_1);
    ft_lstadd_back(&head_b_2, new_node_b_2_1);
    t_number *number_2_2 = (t_number *)malloc(sizeof(t_number));
    number_2_2->value = 2;
    t_list *new_node_b_2_2 = ft_lstnew(number_2_2);
    ft_lstadd_back(&head_b_2, new_node_b_2_2);
    stacks->a_head = head_a_2;
    stacks->b_head = head_b_2;
    sb(stacks);
    assert(stacks->a_head == NULL);
    assert(stacks->b_head->content == number_2_2);
    assert(stacks->b_head->next->content == number_2_1);
    ft_lstclear(&head_b_2, free);

    // A EMPTY LIST B 3 LIST WITH THREE ELEMENTS
    t_list *head_a_3;
    t_list *head_b_3;
    head_a_3 = NULL;
    head_b_3 = NULL;
    t_number *number_3_1 = (t_number *)malloc(sizeof(t_number));
    number_3_1->value = 1;
    t_list *new_node_b_3_1 = ft_lstnew(number_3_1);
    ft_lstadd_back(&head_b_3, new_node_b_3_1);
    t_number *number_3_2 = (t_number *)malloc(sizeof(t_number));
    number_3_2->value = 2;
    t_list *new_node_b_3_2 = ft_lstnew(number_3_2);
    ft_lstadd_back(&head_b_3, new_node_b_3_2);
    t_number *number_3_3 = (t_number *)malloc(sizeof(t_number));
    number_3_3->value = 3;
    t_list *new_node_b_3_3 = ft_lstnew(number_3_3);
    ft_lstadd_back(&head_b_3, new_node_b_3_3);
    stacks->a_head = head_a_3;
    stacks->b_head = head_b_3;
    sb(stacks);
    assert(stacks->a_head == NULL);
    assert(stacks->b_head->content == number_3_2);
    assert(stacks->b_head->next->content == number_3_1);
    assert(stacks->b_head->next->next->content == number_3_3);
    ft_lstclear(&head_b_3, free);

    // A EMPTY LIST B 4 LIST WITH FOUR ELEMENTS
    t_list *head_a_4;
    t_list *head_b_4;
    head_a_4 = NULL;
    head_b_4 = NULL;
    t_number *number_4_1 = (t_number *)malloc(sizeof(t_number));
    number_4_1->value = 1;
    t_list *new_node_b_4_1 = ft_lstnew(number_4_1);
    ft_lstadd_back(&head_b_4, new_node_b_4_1);
    t_number *number_4_2 = (t_number *)malloc(sizeof(t_number));
    number_4_2->value = 2;
    t_list *new_node_b_4_2 = ft_lstnew(number_4_2);
    ft_lstadd_back(&head_b_4, new_node_b_4_2);
    t_number *number_4_3 = (t_number *)malloc(sizeof(t_number));
    number_4_3->value = 3;
    t_list *new_node_b_4_3 = ft_lstnew(number_4_3);
    ft_lstadd_back(&head_b_4, new_node_b_4_3);
    t_number *number_4_4 = (t_number *)malloc(sizeof(t_number));
    number_4_4->value = 4;
    t_list *new_node_b_4_4 = ft_lstnew(number_4_4);
    ft_lstadd_back(&head_b_4, new_node_b_4_4);
    stacks->a_head = head_a_4;
    stacks->b_head = head_b_4;
    sb(stacks);
    assert(stacks->a_head == NULL);
    assert(stacks->b_head->content == number_4_2);
    assert(stacks->b_head->next->content == number_4_1);
    assert(stacks->b_head->next->next->content == number_4_3);
    assert(stacks->b_head->next->next->next->content == number_4_4);
    ft_lstclear(&head_b_4, free);
    free(stacks);
}

void test_ss()
{
    t_stacks *stacks;
    // 0 A EMPTY LIST
    t_list *head_a_0;
    t_list *head_b_0;
    stacks = (t_stacks *)malloc(sizeof(t_stacks));
    if (!stacks)
        return;
    head_a_0 = NULL;
    head_b_0 = NULL;
    t_list *new_node_a_0 = ft_lstnew(NULL);
    ft_lstadd_back(&head_a_0, new_node_a_0);
    t_list *new_node_b_0 = ft_lstnew(NULL);
    ft_lstadd_back(&head_b_0, new_node_b_0);
    stacks->a_head = head_a_0;
    stacks->b_head = head_b_0;
    ss(stacks);
    assert(stacks->a_head->content == NULL);
    assert(stacks->b_head->content == NULL);
    ft_lstclear(&head_a_0, free);
    ft_lstclear(&head_b_0, free);
    // A 1 LIST WITH ONE ELEMENT B 1 LIST WITH ONE ELEMENT
    t_list *head_a_1;
    t_list *head_b_1;
    head_a_1 = NULL;
    head_b_1 = NULL;
    t_number *number_1_a = (t_number *)malloc(sizeof(t_number));
    number_1_a->value = 1;
    t_list *new_node_a_1 = ft_lstnew(number_1_a);
    ft_lstadd_back(&head_a_1, new_node_a_1);
    t_number *number_1_b = (t_number *)malloc(sizeof(t_number));
    number_1_b->value = 1;
    t_list *new_node_b_1 = ft_lstnew(number_1_b);
    ft_lstadd_back(&head_b_1, new_node_b_1);
    stacks->a_head = head_a_1;
    stacks->b_head = head_b_1;
    ss(stacks);
    assert(stacks->a_head->content == number_1_a);
    assert(stacks->b_head->content == number_1_b);
    ft_lstclear(&head_a_1, free);
    ft_lstclear(&head_b_1, free);
    // A 2 LIST WITH TWO ELEMENTS B 2 LIST WITH TWO ELEMENTS
    t_list *head_a_2;
    t_list *head_b_2;
    head_a_2 = NULL;
    head_b_2 = NULL;
    t_number *number_2_1_a = (t_number *)malloc(sizeof(t_number));
    number_2_1_a->value = 1;
    t_list *new_node_a_2_1 = ft_lstnew(number_2_1_a);
    ft_lstadd_back(&head_a_2, new_node_a_2_1);
    t_number *number_2_2_a = (t_number *)malloc(sizeof(t_number));
    number_2_2_a->value = 2;
    t_list *new_node_a_2_2 = ft_lstnew(number_2_2_a);
    ft_lstadd_back(&head_a_2, new_node_a_2_2);
    t_number *number_2_1_b = (t_number *)malloc(sizeof(t_number));
    number_2_1_b->value = 1;
    t_list *new_node_b_2_1 = ft_lstnew(number_2_1_b);
    ft_lstadd_back(&head_b_2, new_node_b_2_1);
    t_number *number_2_2_b = (t_number *)malloc(sizeof(t_number));
    number_2_2_b->value = 2;
    t_list *new_node_b_2_2 = ft_lstnew(number_2_2_b);
    ft_lstadd_back(&head_b_2, new_node_b_2_2);
    stacks->a_head = head_a_2;
    stacks->b_head = head_b_2;
    ss(stacks);
    assert(stacks->a_head->content == number_2_2_a);
    assert(stacks->a_head->next->content == number_2_1_a);
    assert(stacks->b_head->content == number_2_2_b);
    assert(stacks->b_head->next->content == number_2_1_b);
    ft_lstclear(&head_a_2, free);
    ft_lstclear(&head_b_2, free);
    // A 3 LIST WITH THREE ELEMENTS B 3 LIST WITH THREE ELEMENTS
    t_list *head_a_3;
    t_list *head_b_3;
    head_a_3 = NULL;
    head_b_3 = NULL;
    t_number *number_3_1_a = (t_number *)malloc(sizeof(t_number));
    number_3_1_a->value = 1;
    t_list *new_node_a_3_1 = ft_lstnew(number_3_1_a);
    ft_lstadd_back(&head_a_3, new_node_a_3_1);
    t_number *number_3_2_a = (t_number *)malloc(sizeof(t_number));
    number_3_2_a->value = 2;
    t_list *new_node_a_3_2 = ft_lstnew(number_3_2_a);
    ft_lstadd_back(&head_a_3, new_node_a_3_2);
    t_number *number_3_3_a = (t_number *)malloc(sizeof(t_number));
    number_3_3_a->value = 3;
    t_list *new_node_a_3_3 = ft_lstnew(number_3_3_a);
    ft_lstadd_back(&head_a_3, new_node_a_3_3);
    t_number *number_3_1_b = (t_number *)malloc(sizeof(t_number));
    number_3_1_b->value = 1;
    t_list *new_node_b_3_1 = ft_lstnew(number_3_1_b);
    ft_lstadd_back(&head_b_3, new_node_b_3_1);
    t_number *number_3_2_b = (t_number *)malloc(sizeof(t_number));
    number_3_2_b->value = 2;
    t_list *new_node_b_3_2 = ft_lstnew(number_3_2_b);
    ft_lstadd_back(&head_b_3, new_node_b_3_2);
    t_number *number_3_3_b = (t_number *)malloc(sizeof(t_number));
    number_3_3_b->value = 3;
    t_list *new_node_b_3_3 = ft_lstnew(number_3_3_b);
    ft_lstadd_back(&head_b_3, new_node_b_3_3);
    stacks->a_head = head_a_3;
    stacks->b_head = head_b_3;
    ss(stacks);
    assert(stacks->a_head->content == number_3_2_a);
    assert(stacks->a_head->next->content == number_3_1_a);
    assert(stacks->a_head->next->next->content == number_3_3_a);
    assert(stacks->b_head->content == number_3_2_b);
    assert(stacks->b_head->next->content == number_3_1_b);
    assert(stacks->b_head->next->next->content == number_3_3_b);
    ft_lstclear(&head_a_3, free);
    ft_lstclear(&head_b_3, free);
    // A 4 LIST WITH FOUR ELEMENTS B 4 LIST WITH FOUR ELEMENTS
    t_list *head_a_4;
    t_list *head_b_4;
    head_a_4 = NULL;
    head_b_4 = NULL;
    t_number *number_4_1_a = (t_number *)malloc(sizeof(t_number));
    number_4_1_a->value = 1;
    t_list *new_node_a_4_1 = ft_lstnew(number_4_1_a);
    ft_lstadd_back(&head_a_4, new_node_a_4_1);
    t_number *number_4_2_a = (t_number *)malloc(sizeof(t_number));
    number_4_2_a->value = 2;
    t_list *new_node_a_4_2 = ft_lstnew(number_4_2_a);
    ft_lstadd_back(&head_a_4, new_node_a_4_2);
    t_number *number_4_3_a = (t_number *)malloc(sizeof(t_number));
    number_4_3_a->value = 3;
    t_list *new_node_a_4_3 = ft_lstnew(number_4_3_a);
    ft_lstadd_back(&head_a_4, new_node_a_4_3);
    t_number *number_4_4_a = (t_number *)malloc(sizeof(t_number));
    number_4_4_a->value = 4;
    t_list *new_node_a_4_4 = ft_lstnew(number_4_4_a);
    ft_lstadd_back(&head_a_4, new_node_a_4_4);
    t_number *number_4_1_b = (t_number *)malloc(sizeof(t_number));
    number_4_1_b->value = 1;
    t_list *new_node_b_4_1 = ft_lstnew(number_4_1_b);
    ft_lstadd_back(&head_b_4, new_node_b_4_1);
    t_number *number_4_2_b = (t_number *)malloc(sizeof(t_number));
    number_4_2_b->value = 2;
    t_list *new_node_b_4_2 = ft_lstnew(number_4_2_b);
    ft_lstadd_back(&head_b_4, new_node_b_4_2);
    t_number *number_4_3_b = (t_number *)malloc(sizeof(t_number));
    number_4_3_b->value = 3;
    t_list *new_node_b_4_3 = ft_lstnew(number_4_3_b);
    ft_lstadd_back(&head_b_4, new_node_b_4_3);
    t_number *number_4_4_b = (t_number *)malloc(sizeof(t_number));
    number_4_4_b->value = 4;
    t_list *new_node_b_4_4 = ft_lstnew(number_4_4_b);
    ft_lstadd_back(&head_b_4, new_node_b_4_4);
    stacks->a_head = head_a_4;
    stacks->b_head = head_b_4;
    ss(stacks);
    assert(stacks->a_head->content == number_4_2_a);
    assert(stacks->a_head->next->content == number_4_1_a);
    assert(stacks->a_head->next->next->content == number_4_3_a);
    assert(stacks->a_head->next->next->next->content == number_4_4_a);
    assert(stacks->b_head->content == number_4_2_b);
    assert(stacks->b_head->next->content == number_4_1_b);
    assert(stacks->b_head->next->next->content == number_4_3_b);
    assert(stacks->b_head->next->next->next->content == number_4_4_b);
    ft_lstclear(&head_a_4, free);
    ft_lstclear(&head_b_4, free);
    free(stacks);
}

void    test_pa()
{
    t_stacks *stacks;
    stacks = (t_stacks *)malloc(sizeof(t_stacks));
    if (!stacks)
        return;
    // TEST0 A EMPTY LIST B 1 LIST WITH ONE ELEMENT
    t_list *head_a_0;
    t_list *head_b_1;
    head_a_0 = NULL;
    head_b_1 = NULL;
    t_number *number_1 = (t_number *)malloc(sizeof(t_number));
    number_1->value = 1;
    t_list *new_node_b_1 = ft_lstnew(number_1);
    ft_lstadd_back(&head_b_1, new_node_b_1);
    stacks->a_head = head_a_0;
    stacks->b_head = head_b_1;
    pa(stacks);
    assert(stacks->a_head->content == number_1);
    assert(stacks->b_head == NULL);
    ft_lstclear(&head_a_0, free);
    ft_lstclear(&head_b_1, free);
    // TEST1 A 1 ELEMENT B EMPTY LIST
    t_list *head_a_1;
    t_list *head_b_0;
    head_a_1 = NULL;
    head_b_0 = NULL;
    t_number *number_1_a = (t_number *)malloc(sizeof(t_number));
    number_1_a->value = 1;
    t_list *new_node_a_1 = ft_lstnew(number_1_a);
    ft_lstadd_back(&head_a_1, new_node_a_1);
    stacks->a_head = head_a_1;
    stacks->b_head = head_b_0;
    pa(stacks);
    assert(stacks->a_head->content == number_1_a);
    assert(stacks->b_head == NULL);
    ft_lstclear(&head_a_1, free);
    ft_lstclear(&head_b_0, free);
    
    // TEST2  A 1 ELEMENT B 1 ELEMENT
    t_list *head_a_2;
    t_list *head_b_2;
    head_a_2 = NULL;
    head_b_2 = NULL;

    t_number *number_2_a = (t_number *)malloc(sizeof(t_number));
    number_2_a->value = 1;
    t_list *new_node_a_2 = ft_lstnew(number_2_a);
    ft_lstadd_back(&head_a_2, new_node_a_2);

    t_number *number_2_b = (t_number *)malloc(sizeof(t_number));
    number_2_b->value = 42;
    t_list *new_node_b_2 = ft_lstnew(number_2_b);
    ft_lstadd_back(&head_b_2, new_node_b_2);
    stacks->a_head = head_a_2;
    stacks->b_head = head_b_2;

    pa(stacks);

    assert(stacks->a_head->content == number_2_b);
    assert(stacks->a_head->next->content == number_2_a);
    assert(stacks->b_head == NULL);
    ft_lstclear(&(stacks->a_head), free);
    ft_lstclear(&(stacks->b_head), free);
    

    free(stacks);


}


void test_pb()
{
    t_stacks *stacks;
    stacks = (t_stacks *)malloc(sizeof(t_stacks));
    if (!stacks)
        return;
    // TEST0 A EMPTY LIST B 1 LIST WITH ONE ELEMENT
    t_list *head_a_0;
    t_list *head_b_1;
    head_a_0 = NULL;
    head_b_1 = NULL;
    t_number *number_1 = (t_number *)malloc(sizeof(t_number));
    number_1->value = 1;
    t_list *new_node_b_1 = ft_lstnew(number_1);
    ft_lstadd_back(&head_b_1, new_node_b_1);
    stacks->a_head = head_a_0;
    stacks->b_head = head_b_1;
    pb(stacks);
    assert(stacks->a_head == NULL);
    assert(stacks->b_head->content == number_1);
    ft_lstclear(&head_a_0, free);
    ft_lstclear(&head_b_1, free);
    // TEST1 A 1 ELEMENT B EMPTY LIST
    t_list *head_a_1;
    t_list *head_b_0;
    head_a_1 = NULL;
    head_b_0 = NULL;
    t_number *number_1_a = (t_number *)malloc(sizeof(t_number));
    number_1_a->value = 1;
    t_list *new_node_a_1 = ft_lstnew(number_1_a);
    ft_lstadd_back(&head_a_1, new_node_a_1);
    stacks->a_head = head_a_1;
    stacks->b_head = head_b_0;
    pb(stacks);
    assert(stacks->a_head == NULL);
    assert(stacks->b_head->content == number_1_a);
    ft_lstclear(&head_a_1, free);
    ft_lstclear(&head_b_0, free);
    
    // TEST2  A 1 ELEMENT B 1 ELEMENT
    t_list *head_a_2;
    t_list *head_b_2;
    head_a_2 = NULL;
    head_b_2 = NULL;

    t_number *number_2_a = (t_number *)malloc(sizeof(t_number));
    number_2_a->value = 1;
    t_list *new_node_a_2 = ft_lstnew(number_2_a);
    ft_lstadd_back(&head_a_2, new_node_a_2);

    t_number *number_2_b = (t_number *)malloc(sizeof(t_number));
    number_2_b->value = 42;
    t_list *new_node_b_2 = ft_lstnew(number_2_b);
    ft_lstadd_back(&head_b_2, new_node_b_2);

    stacks->a_head = head_a_2;
    stacks->b_head = head_b_2;

    pb(stacks);

    assert(stacks->b_head->content == number_2_a);
    assert(stacks->b_head->next->content == number_2_b);
    assert(stacks->a_head == NULL);
    // ft_lstclear(&(stacks->a_head), free);
    ft_lstclear(&(stacks->b_head), free);

    //TEST3 A 2 ELEMENTS B 1 ELEMENT
    t_list *head_a_3;
    t_list *head_b_3;
    head_a_3 = NULL;
    head_b_3 = NULL;

    t_number *number_3_1_a = (t_number *)malloc(sizeof(t_number));
    number_3_1_a->value = 1;
    t_list *new_node_a_3_1 = ft_lstnew(number_3_1_a);
    ft_lstadd_back(&head_a_3, new_node_a_3_1);

    t_number *number_3_2_a = (t_number *)malloc(sizeof(t_number));
    number_3_2_a->value = 2;
    t_list *new_node_a_3_2 = ft_lstnew(number_3_2_a);
    ft_lstadd_back(&head_a_3, new_node_a_3_2);

    t_number *number_3_b = (t_number *)malloc(sizeof(t_number));
    number_3_b->value = 1;
    t_list *new_node_b_3 = ft_lstnew(number_3_b);
    ft_lstadd_back(&head_b_3, new_node_b_3);

    stacks->a_head = head_a_3;
    stacks->b_head = head_b_3;

    pb(stacks);
    assert(stacks->a_head->content == number_3_2_a);
    assert(stacks->b_head->content == number_3_1_a);
    assert(stacks->b_head->next->content == number_3_b);
    ft_lstclear(&(stacks->b_head), free);
    ft_lstclear(&(stacks->a_head), free);
    free(stacks);
}
void test_ra()
{
    t_stacks *stacks;
    stacks = (t_stacks *)malloc(sizeof(t_stacks));
    if (!stacks)
        return;
    
    // TEST0 A empty list B empty list
    t_list *head_a_0;
    t_list *head_b_0;
    head_a_0 = NULL;
    head_b_0 = NULL;
    stacks->a_head = head_a_0;
    stacks->b_head = head_b_0;

    ra(stacks);

    assert(stacks->a_head == NULL);
    assert(stacks->b_head == NULL);

    // TEST1 A 1 ELEMENT B empty list
    t_list *head_a_1;
    t_list *head_b_1;
    head_a_1 = NULL;
    head_b_1 = NULL;

    t_number *number_a_1_0 = (t_number *)malloc(sizeof(t_number));
    number_a_1_0->value = 42;
    t_list *new_node_a_1_0 = ft_lstnew(number_a_1_0);
    ft_lstadd_back(&head_a_1, new_node_a_1_0);

    stacks->a_head = head_a_1;
    stacks->b_head = head_b_1;

    ra(stacks);

    assert(stacks->a_head->content == number_a_1_0);
    assert(stacks->b_head == NULL);

    ft_lstclear(&(stacks->a_head), free);

    // TEST2 A 2 ELEMENTS B empty list
    t_list *head_a_2;
    t_list *head_b_2;
    head_a_2 = NULL;
    head_b_2 = NULL;

    t_number *number_a_2_0 = (t_number *)malloc(sizeof(t_number));
    number_a_2_0->value = 1;
    t_list *new_node_a_2_0 = ft_lstnew(number_a_2_0);
    ft_lstadd_back(&head_a_2, new_node_a_2_0);

    t_number *number_a_2_1 = (t_number *)malloc(sizeof(t_number));
    number_a_2_1->value = 2;
    t_list *new_node_a_2_1 = ft_lstnew(number_a_2_1);
    ft_lstadd_back(&head_a_2, new_node_a_2_1);

    stacks->a_head = head_a_2;
    stacks->b_head = head_b_2;

    ra(stacks);

    // elements for a are rotated yeah?
    assert(stacks->a_head->content == number_a_2_1);
    assert(stacks->a_head->next->content == number_a_2_0);
    assert(stacks->b_head == NULL);

    ft_lstclear(&(stacks->a_head), free);


    // TEST3 A 3 ELEMENTS B empty list
    t_list *head_a_3;
    t_list *head_b_3;
    head_a_3 = NULL;
    head_b_3 = NULL;

    t_number *number_a_3_0 = (t_number *)malloc(sizeof(t_number));
    number_a_3_0->value = 0;
    t_list *new_node_a_3_0 = ft_lstnew(number_a_3_0);
    ft_lstadd_back(&head_a_3, new_node_a_3_0);

    t_number *number_a_3_1 = (t_number *)malloc(sizeof(t_number));
    number_a_3_1->value = 1;
    t_list *new_node_a_3_1 = ft_lstnew(number_a_3_1);
    ft_lstadd_back(&head_a_3, new_node_a_3_1);

    t_number *number_a_3_2 = (t_number *)malloc(sizeof(t_number));
    number_a_3_2->value = 2;
    t_list *new_node_a_3_2 = ft_lstnew(number_a_3_2);
    ft_lstadd_back(&head_a_3, new_node_a_3_2);

    stacks->a_head = head_a_3;
    stacks->b_head = head_b_3;

    ra(stacks);

    assert(stacks->a_head->content == number_a_3_1);
    assert(stacks->a_head->next->content == number_a_3_2);
    assert(stacks->a_head->next->next->content == number_a_3_0);
    assert(stacks->b_head == NULL);

    ft_lstclear(&(stacks->a_head), free);

    // TEST4 A 4 ELEMENTS B empty list
    t_list *head_a_4;
    t_list *head_b_4;
    head_a_4 = NULL;
    head_b_4 = NULL;

    t_number *number_a_4_0 = (t_number *)malloc(sizeof(t_number));
    number_a_4_0->value = 0;
    t_list *new_node_a_4_0 = ft_lstnew(number_a_4_0);
    ft_lstadd_back(&head_a_4, new_node_a_4_0);

    t_number *number_a_4_1 = (t_number *)malloc(sizeof(t_number));
    number_a_4_1->value = 1;
    t_list *new_node_a_4_1 = ft_lstnew(number_a_4_1);
    ft_lstadd_back(&head_a_4, new_node_a_4_1);

    t_number *number_a_4_2 = (t_number *)malloc(sizeof(t_number));
    number_a_4_2->value = 2;
    t_list *new_node_a_4_2 = ft_lstnew(number_a_4_2);
    ft_lstadd_back(&head_a_4, new_node_a_4_2);

    t_number *number_a_4_3 = (t_number *)malloc(sizeof(t_number));
    number_a_4_3->value = 3;
    t_list *new_node_a_4_3 = ft_lstnew(number_a_4_3);
    ft_lstadd_back(&head_a_4, new_node_a_4_3);

    stacks->a_head = head_a_4;
    stacks->b_head = head_b_4;

    ra(stacks);

    // elements for a are rotated yeah?
    assert(stacks->a_head->content == number_a_4_1);
    assert(stacks->a_head->next->content == number_a_4_2);
    assert(stacks->a_head->next->next->content == number_a_4_3);
    assert(stacks->a_head->next->next->next->content == number_a_4_0);
    assert(stacks->b_head == NULL);

    ft_lstclear(&(stacks->a_head), free);

    free(stacks);
}

int main(void)
{
    test_sa();
    test_sb();
    test_ss();
    test_pa();
    test_pb();
    test_ra();
    return(0);
}