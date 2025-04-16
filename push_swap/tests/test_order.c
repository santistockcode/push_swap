#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "./../include/push_swap.h"

void test_order_2()
{
    t_list *head_a;
    head_a = NULL;

    t_number *number_1 = (t_number *)malloc(sizeof(t_number));
    number_1->value = 2;
    t_list *new_node_1 = ft_lstnew(number_1);
    ft_lstadd_back(&head_a, new_node_1);

    t_number *number_2 = (t_number *)malloc(sizeof(t_number));
    number_2->value = 1;
    t_list *new_node_2 = ft_lstnew(number_2);
    ft_lstadd_back(&head_a, new_node_2);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);

    ft_lstclear(&head_a, free);

    // test1
    t_list *head_a1;
    head_a1 = NULL;

    t_number *number_4 = (t_number *)malloc(sizeof(t_number));
    number_4->value = INT_MAX;
    t_list *new_node_4 = ft_lstnew(number_4);
    ft_lstadd_back(&head_a1, new_node_4);

    t_number *number_5 = (t_number *)malloc(sizeof(t_number));
    number_5->value = INT_MIN;
    t_list *new_node_5 = ft_lstnew(number_5);
    ft_lstadd_back(&head_a1, new_node_5);

    order_a(head_a1);

    assert(((t_number *)head_a1->content)->value == INT_MIN);
    assert(((t_number *)head_a1->next->content)->value == INT_MAX);

    ft_lstclear(&head_a1, free);
}

void test_order_3()
{
    t_list *head_a;
    head_a = NULL;

    // Test 1: 1 2 3
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
    if (!is_ordered(head_a))
        order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);

    ft_lstclear(&head_a, free);

    // Test 2: 1 3 2
    t_number *number_4 = (t_number *)malloc(sizeof(t_number));
    number_4->value = 1;
    t_list *new_node_4 = ft_lstnew(number_4);
    ft_lstadd_back(&head_a, new_node_4);

    t_number *number_5 = (t_number *)malloc(sizeof(t_number));
    number_5->value = 3;
    t_list *new_node_5 = ft_lstnew(number_5);
    ft_lstadd_back(&head_a, new_node_5);

    t_number *number_6 = (t_number *)malloc(sizeof(t_number));
    number_6->value = 2;
    t_list *new_node_6 = ft_lstnew(number_6);
    ft_lstadd_back(&head_a, new_node_6);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);

    ft_lstclear(&head_a, free);

    // Test 3: 2 1 3
    t_number *number_7 = (t_number *)malloc(sizeof(t_number));
    number_7->value = 2;
    t_list *new_node_7 = ft_lstnew(number_7);
    ft_lstadd_back(&head_a, new_node_7);

    t_number *number_8 = (t_number *)malloc(sizeof(t_number));
    number_8->value = 1;
    t_list *new_node_8 = ft_lstnew(number_8);
    ft_lstadd_back(&head_a, new_node_8);

    t_number *number_9 = (t_number *)malloc(sizeof(t_number));
    number_9->value = 3;
    t_list *new_node_9 = ft_lstnew(number_9);
    ft_lstadd_back(&head_a, new_node_9);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);

    ft_lstclear(&head_a, free);

    // Test 4: 2 3 1
    t_number *number_10 = (t_number *)malloc(sizeof(t_number));
    number_10->value = 2;
    t_list *new_node_10 = ft_lstnew(number_10);
    ft_lstadd_back(&head_a, new_node_10);

    t_number *number_11 = (t_number *)malloc(sizeof(t_number));
    number_11->value = 3;
    t_list *new_node_11 = ft_lstnew(number_11);
    ft_lstadd_back(&head_a, new_node_11);

    t_number *number_12 = (t_number *)malloc(sizeof(t_number));
    number_12->value = 1;
    t_list *new_node_12 = ft_lstnew(number_12);
    ft_lstadd_back(&head_a, new_node_12);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);

    ft_lstclear(&head_a, free);

    // Test 5: 3 1 2
    t_number *number_13 = (t_number *)malloc(sizeof(t_number));
    number_13->value = 3;
    t_list *new_node_13 = ft_lstnew(number_13);
    ft_lstadd_back(&head_a, new_node_13);

    t_number *number_14 = (t_number *)malloc(sizeof(t_number));
    number_14->value = 1;
    t_list *new_node_14 = ft_lstnew(number_14);
    ft_lstadd_back(&head_a, new_node_14);

    t_number *number_15 = (t_number *)malloc(sizeof(t_number));
    number_15->value = 2;
    t_list *new_node_15 = ft_lstnew(number_15);
    ft_lstadd_back(&head_a, new_node_15);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);

    ft_lstclear(&head_a, free);

    // Test 6: 3 2 1
    t_number *number_16 = (t_number *)malloc(sizeof(t_number));
    number_16->value = 3;
    t_list *new_node_16 = ft_lstnew(number_16);
    ft_lstadd_back(&head_a, new_node_16);

    t_number *number_17 = (t_number *)malloc(sizeof(t_number));
    number_17->value = 2;
    t_list *new_node_17 = ft_lstnew(number_17);
    ft_lstadd_back(&head_a, new_node_17);

    t_number *number_18 = (t_number *)malloc(sizeof(t_number));
    number_18->value = 1;
    t_list *new_node_18 = ft_lstnew(number_18);
    ft_lstadd_back(&head_a, new_node_18);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);

    ft_lstclear(&head_a, free);
}

void test_order_4()
{
    t_list *head_a;
    head_a = NULL;

    // Test 1: 1 2 4 3
    t_number *number_1 = (t_number *)malloc(sizeof(t_number));
    number_1->value = 1;
    t_list *new_node_1 = ft_lstnew(number_1);
    ft_lstadd_back(&head_a, new_node_1);

    t_number *number_2 = (t_number *)malloc(sizeof(t_number));
    number_2->value = 2;
    t_list *new_node_2 = ft_lstnew(number_2);
    ft_lstadd_back(&head_a, new_node_2);

    t_number *number_3 = (t_number *)malloc(sizeof(t_number));
    number_3->value = 4;
    t_list *new_node_3 = ft_lstnew(number_3);
    ft_lstadd_back(&head_a, new_node_3);

    t_number *number_4 = (t_number *)malloc(sizeof(t_number));
    number_4->value = 3;
    t_list *new_node_4 = ft_lstnew(number_4);
    ft_lstadd_back(&head_a, new_node_4);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);

    ft_lstclear(&head_a, free);

    // Test 2: 1 3 2 4
    t_number *number_5 = (t_number *)malloc(sizeof(t_number));
    number_5->value = 1;
    t_list *new_node_5 = ft_lstnew(number_5);
    ft_lstadd_back(&head_a, new_node_5);

    t_number *number_6 = (t_number *)malloc(sizeof(t_number));
    number_6->value = 3;
    t_list *new_node_6 = ft_lstnew(number_6);
    ft_lstadd_back(&head_a, new_node_6);

    t_number *number_7 = (t_number *)malloc(sizeof(t_number));
    number_7->value = 2;
    t_list *new_node_7 = ft_lstnew(number_7);
    ft_lstadd_back(&head_a, new_node_7);

    t_number *number_8 = (t_number *)malloc(sizeof(t_number));
    number_8->value = 4;
    t_list *new_node_8 = ft_lstnew(number_8);
    ft_lstadd_back(&head_a, new_node_8);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);

    ft_lstclear(&head_a, free);

    // Test 3: 1 3 4 2
    t_number *number_9 = (t_number *)malloc(sizeof(t_number));
    number_9->value = 1;
    t_list *new_node_9 = ft_lstnew(number_9);
    ft_lstadd_back(&head_a, new_node_9);

    t_number *number_10 = (t_number *)malloc(sizeof(t_number));
    number_10->value = 3;
    t_list *new_node_10 = ft_lstnew(number_10);
    ft_lstadd_back(&head_a, new_node_10);

    t_number *number_11 = (t_number *)malloc(sizeof(t_number));
    number_11->value = 4;
    t_list *new_node_11 = ft_lstnew(number_11);
    ft_lstadd_back(&head_a, new_node_11);

    t_number *number_12 = (t_number *)malloc(sizeof(t_number));
    number_12->value = 2;
    t_list *new_node_12 = ft_lstnew(number_12);
    ft_lstadd_back(&head_a, new_node_12);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);

    ft_lstclear(&head_a, free);

    // Test 4: 1 4 2 3
    t_number *number_13 = (t_number *)malloc(sizeof(t_number));
    number_13->value = 1;
    t_list *new_node_13 = ft_lstnew(number_13);
    ft_lstadd_back(&head_a, new_node_13);

    t_number *number_14 = (t_number *)malloc(sizeof(t_number));
    number_14->value = 4;
    t_list *new_node_14 = ft_lstnew(number_14);
    ft_lstadd_back(&head_a, new_node_14);

    t_number *number_15 = (t_number *)malloc(sizeof(t_number));
    number_15->value = 2;
    t_list *new_node_15 = ft_lstnew(number_15);
    ft_lstadd_back(&head_a, new_node_15);

    t_number *number_16 = (t_number *)malloc(sizeof(t_number));
    number_16->value = 3;
    t_list *new_node_16 = ft_lstnew(number_16);
    ft_lstadd_back(&head_a, new_node_16);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);

    ft_lstclear(&head_a, free);

    // // Test 5: 1 4 3 2
    t_number *number_17 = (t_number *)malloc(sizeof(t_number));
    number_17->value = 1;
    t_list *new_node_17 = ft_lstnew(number_17);
    ft_lstadd_back(&head_a, new_node_17);

    t_number *number_18 = (t_number *)malloc(sizeof(t_number));
    number_18->value = 4;
    t_list *new_node_18 = ft_lstnew(number_18);
    ft_lstadd_back(&head_a, new_node_18);

    t_number *number_19 = (t_number *)malloc(sizeof(t_number));
    number_19->value = 3;
    t_list *new_node_19 = ft_lstnew(number_19);
    ft_lstadd_back(&head_a, new_node_19);

    t_number *number_20 = (t_number *)malloc(sizeof(t_number));
    number_20->value = 2;
    t_list *new_node_20 = ft_lstnew(number_20);
    ft_lstadd_back(&head_a, new_node_20);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);

    ft_lstclear(&head_a, free);

    // // Test 6: 2 1 3 4
    t_number *number_21 = (t_number *)malloc(sizeof(t_number));
    number_21->value = 2;
    t_list *new_node_21 = ft_lstnew(number_21);
    ft_lstadd_back(&head_a, new_node_21);

    t_number *number_22 = (t_number *)malloc(sizeof(t_number));
    number_22->value = 1;
    t_list *new_node_22 = ft_lstnew(number_22);
    ft_lstadd_back(&head_a, new_node_22);

    t_number *number_23 = (t_number *)malloc(sizeof(t_number));
    number_23->value = 3;
    t_list *new_node_23 = ft_lstnew(number_23);
    ft_lstadd_back(&head_a, new_node_23);

    t_number *number_24 = (t_number *)malloc(sizeof(t_number));
    number_24->value = 4;
    t_list *new_node_24 = ft_lstnew(number_24);
    ft_lstadd_back(&head_a, new_node_24);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);

    ft_lstclear(&head_a, free);

    // // Test 7: 2 1 4 3
    t_number *number_25 = (t_number *)malloc(sizeof(t_number));
    number_25->value = 2;
    t_list *new_node_25 = ft_lstnew(number_25);
    ft_lstadd_back(&head_a, new_node_25);

    t_number *number_26 = (t_number *)malloc(sizeof(t_number));
    number_26->value = 1;
    t_list *new_node_26 = ft_lstnew(number_26);
    ft_lstadd_back(&head_a, new_node_26);

    t_number *number_27 = (t_number *)malloc(sizeof(t_number));
    number_27->value = 4;
    t_list *new_node_27 = ft_lstnew(number_27);
    ft_lstadd_back(&head_a, new_node_27);

    t_number *number_28 = (t_number *)malloc(sizeof(t_number));
    number_28->value = 3;
    t_list *new_node_28 = ft_lstnew(number_28);
    ft_lstadd_back(&head_a, new_node_28);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);

    ft_lstclear(&head_a, free);

    // // Test 8: 2 3 1 4
    t_number *number_29 = (t_number *)malloc(sizeof(t_number));
    number_29->value = 2;
    t_list *new_node_29 = ft_lstnew(number_29);
    ft_lstadd_back(&head_a, new_node_29);

    t_number *number_30 = (t_number *)malloc(sizeof(t_number));
    number_30->value = 3;
    t_list *new_node_30 = ft_lstnew(number_30);
    ft_lstadd_back(&head_a, new_node_30);

    t_number *number_31 = (t_number *)malloc(sizeof(t_number));
    number_31->value = 1;
    t_list *new_node_31 = ft_lstnew(number_31);
    ft_lstadd_back(&head_a, new_node_31);

    t_number *number_32 = (t_number *)malloc(sizeof(t_number));
    number_32->value = 4;
    t_list *new_node_32 = ft_lstnew(number_32);
    ft_lstadd_back(&head_a, new_node_32);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);

    ft_lstclear(&head_a, free);

    // // Test 9: 2 3 4 1
    t_number *number_33 = (t_number *)malloc(sizeof(t_number));
    number_33->value = 2;
    t_list *new_node_33 = ft_lstnew(number_33);
    ft_lstadd_back(&head_a, new_node_33);

    t_number *number_34 = (t_number *)malloc(sizeof(t_number));
    number_34->value = 3;
    t_list *new_node_34 = ft_lstnew(number_34);
    ft_lstadd_back(&head_a, new_node_34);

    t_number *number_35 = (t_number *)malloc(sizeof(t_number));
    number_35->value = 4;
    t_list *new_node_35 = ft_lstnew(number_35);
    ft_lstadd_back(&head_a, new_node_35);

    t_number *number_36 = (t_number *)malloc(sizeof(t_number));
    number_36->value = 1;
    t_list *new_node_36 = ft_lstnew(number_36);
    ft_lstadd_back(&head_a, new_node_36);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);

    ft_lstclear(&head_a, free);

    // Test 10: 3 1 2 4
    t_number *number_37 = (t_number *)malloc(sizeof(t_number));
    number_37->value = 3;
    t_list *new_node_37 = ft_lstnew(number_37);
    ft_lstadd_back(&head_a, new_node_37);

    t_number *number_38 = (t_number *)malloc(sizeof(t_number));
    number_38->value = 1;
    t_list *new_node_38 = ft_lstnew(number_38);
    ft_lstadd_back(&head_a, new_node_38);

    t_number *number_39 = (t_number *)malloc(sizeof(t_number));
    number_39->value = 2;
    t_list *new_node_39 = ft_lstnew(number_39);
    ft_lstadd_back(&head_a, new_node_39);

    t_number *number_40 = (t_number *)malloc(sizeof(t_number));
    number_40->value = 4;
    t_list *new_node_40 = ft_lstnew(number_40);
    ft_lstadd_back(&head_a, new_node_40);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);

    ft_lstclear(&head_a, free);

    // Test 11: 3 1 4 2
    t_number *number_41 = (t_number *)malloc(sizeof(t_number));
    number_41->value = 3;
    t_list *new_node_41 = ft_lstnew(number_41);
    ft_lstadd_back(&head_a, new_node_41);

    t_number *number_42 = (t_number *)malloc(sizeof(t_number));
    number_42->value = 1;
    t_list *new_node_42 = ft_lstnew(number_42);
    ft_lstadd_back(&head_a, new_node_42);

    t_number *number_43 = (t_number *)malloc(sizeof(t_number));
    number_43->value = 4;
    t_list *new_node_43 = ft_lstnew(number_43);
    ft_lstadd_back(&head_a, new_node_43);

    t_number *number_44 = (t_number *)malloc(sizeof(t_number));
    number_44->value = 2;
    t_list *new_node_44 = ft_lstnew(number_44);
    ft_lstadd_back(&head_a, new_node_44);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);

    ft_lstclear(&head_a, free);

    // Test 12: 3 2 1 4
    t_number *number_45 = (t_number *)malloc(sizeof(t_number));
    number_45->value = 3;
    t_list *new_node_45 = ft_lstnew(number_45);
    ft_lstadd_back(&head_a, new_node_45);

    t_number *number_46 = (t_number *)malloc(sizeof(t_number));
    number_46->value = 2;
    t_list *new_node_46 = ft_lstnew(number_46);
    ft_lstadd_back(&head_a, new_node_46);

    t_number *number_47 = (t_number *)malloc(sizeof(t_number));
    number_47->value = 1;
    t_list *new_node_47 = ft_lstnew(number_47);
    ft_lstadd_back(&head_a, new_node_47);

    t_number *number_48 = (t_number *)malloc(sizeof(t_number));
    number_48->value = 4;
    t_list *new_node_48 = ft_lstnew(number_48);
    ft_lstadd_back(&head_a, new_node_48);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);

    ft_lstclear(&head_a, free);
}

void test_order_5()
{
    t_list *head_a;
    head_a = NULL;

    // Test 1: 1 2 3 5 4
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

    t_number *number_4 = (t_number *)malloc(sizeof(t_number));
    number_4->value = 5;
    t_list *new_node_4 = ft_lstnew(number_4);
    ft_lstadd_back(&head_a, new_node_4);

    t_number *number_5 = (t_number *)malloc(sizeof(t_number));
    number_5->value = 4;
    t_list *new_node_5 = ft_lstnew(number_5);
    ft_lstadd_back(&head_a, new_node_5);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);
    assert(((t_number *)head_a->next->next->next->next->content)->value == 5);

    ft_lstclear(&head_a, free);

    // Test 2: 1 2 4 3 5
    t_number *number_6 = (t_number *)malloc(sizeof(t_number));
    number_6->value = 1;
    t_list *new_node_6 = ft_lstnew(number_6);
    ft_lstadd_back(&head_a, new_node_6);

    t_number *number_7 = (t_number *)malloc(sizeof(t_number));
    number_7->value = 2;
    t_list *new_node_7 = ft_lstnew(number_7);
    ft_lstadd_back(&head_a, new_node_7);

    t_number *number_8 = (t_number *)malloc(sizeof(t_number));
    number_8->value = 4;
    t_list *new_node_8 = ft_lstnew(number_8);
    ft_lstadd_back(&head_a, new_node_8);

    t_number *number_9 = (t_number *)malloc(sizeof(t_number));
    number_9->value = 3;
    t_list *new_node_9 = ft_lstnew(number_9);
    ft_lstadd_back(&head_a, new_node_9);

    t_number *number_10 = (t_number *)malloc(sizeof(t_number));
    number_10->value = 5;
    t_list *new_node_10 = ft_lstnew(number_10);
    ft_lstadd_back(&head_a, new_node_10);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);
    assert(((t_number *)head_a->next->next->next->next->content)->value == 5);

    ft_lstclear(&head_a, free);

    // Test 3: 1 2 4 5 3
    t_number *number_11 = (t_number *)malloc(sizeof(t_number));
    number_11->value = 1;
    t_list *new_node_11 = ft_lstnew(number_11);
    ft_lstadd_back(&head_a, new_node_11);

    t_number *number_12 = (t_number *)malloc(sizeof(t_number));
    number_12->value = 2;
    t_list *new_node_12 = ft_lstnew(number_12);
    ft_lstadd_back(&head_a, new_node_12);

    t_number *number_13 = (t_number *)malloc(sizeof(t_number));
    number_13->value = 4;
    t_list *new_node_13 = ft_lstnew(number_13);
    ft_lstadd_back(&head_a, new_node_13);

    t_number *number_14 = (t_number *)malloc(sizeof(t_number));
    number_14->value = 5;
    t_list *new_node_14 = ft_lstnew(number_14);
    ft_lstadd_back(&head_a, new_node_14);

    t_number *number_15 = (t_number *)malloc(sizeof(t_number));
    number_15->value = 3;
    t_list *new_node_15 = ft_lstnew(number_15);
    ft_lstadd_back(&head_a, new_node_15);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);
    assert(((t_number *)head_a->next->next->next->next->content)->value == 5);

    ft_lstclear(&head_a, free);

    // Test 4: 1 2 5 3 4
    t_number *number_16 = (t_number *)malloc(sizeof(t_number));
    number_16->value = 1;
    t_list *new_node_16 = ft_lstnew(number_16);
    ft_lstadd_back(&head_a, new_node_16);

    t_number *number_17 = (t_number *)malloc(sizeof(t_number));
    number_17->value = 2;
    t_list *new_node_17 = ft_lstnew(number_17);
    ft_lstadd_back(&head_a, new_node_17);

    t_number *number_18 = (t_number *)malloc(sizeof(t_number));
    number_18->value = 5;
    t_list *new_node_18 = ft_lstnew(number_18);
    ft_lstadd_back(&head_a, new_node_18);

    t_number *number_19 = (t_number *)malloc(sizeof(t_number));
    number_19->value = 3;
    t_list *new_node_19 = ft_lstnew(number_19);
    ft_lstadd_back(&head_a, new_node_19);

    t_number *number_20 = (t_number *)malloc(sizeof(t_number));
    number_20->value = 4;
    t_list *new_node_20 = ft_lstnew(number_20);
    ft_lstadd_back(&head_a, new_node_20);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);
    assert(((t_number *)head_a->next->next->next->next->content)->value == 5);

    ft_lstclear(&head_a, free);

    // Test 5: 1 3 2 4 5
    t_number *number_21 = (t_number *)malloc(sizeof(t_number));
    number_21->value = 1;
    t_list *new_node_21 = ft_lstnew(number_21);
    ft_lstadd_back(&head_a, new_node_21);

    t_number *number_22 = (t_number *)malloc(sizeof(t_number));
    number_22->value = 3;
    t_list *new_node_22 = ft_lstnew(number_22);
    ft_lstadd_back(&head_a, new_node_22);

    t_number *number_23 = (t_number *)malloc(sizeof(t_number));
    number_23->value = 2;
    t_list *new_node_23 = ft_lstnew(number_23);
    ft_lstadd_back(&head_a, new_node_23);

    t_number *number_24 = (t_number *)malloc(sizeof(t_number));
    number_24->value = 4;
    t_list *new_node_24 = ft_lstnew(number_24);
    ft_lstadd_back(&head_a, new_node_24);

    t_number *number_25 = (t_number *)malloc(sizeof(t_number));
    number_25->value = 5;
    t_list *new_node_25 = ft_lstnew(number_25);
    ft_lstadd_back(&head_a, new_node_25);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);
    assert(((t_number *)head_a->next->next->next->next->content)->value == 5);

    ft_lstclear(&head_a, free);

    // Test 6: 1 3 2 5 4
    t_number *number_26 = (t_number *)malloc(sizeof(t_number));
    number_26->value = 1;
    t_list *new_node_26 = ft_lstnew(number_26);
    ft_lstadd_back(&head_a, new_node_26);

    t_number *number_27 = (t_number *)malloc(sizeof(t_number));
    number_27->value = 3;
    t_list *new_node_27 = ft_lstnew(number_27);
    ft_lstadd_back(&head_a, new_node_27);

    t_number *number_28 = (t_number *)malloc(sizeof(t_number));
    number_28->value = 2;
    t_list *new_node_28 = ft_lstnew(number_28);
    ft_lstadd_back(&head_a, new_node_28);

    t_number *number_29 = (t_number *)malloc(sizeof(t_number));
    number_29->value = 5;
    t_list *new_node_29 = ft_lstnew(number_29);
    ft_lstadd_back(&head_a, new_node_29);

    t_number *number_30 = (t_number *)malloc(sizeof(t_number));
    number_30->value = 4;
    t_list *new_node_30 = ft_lstnew(number_30);
    ft_lstadd_back(&head_a, new_node_30);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);
    assert(((t_number *)head_a->next->next->next->next->content)->value == 5);

    ft_lstclear(&head_a, free);

    // Test 7: 1 3 4 2 5
    t_number *number_31 = (t_number *)malloc(sizeof(t_number));
    number_31->value = 1;
    t_list *new_node_31 = ft_lstnew(number_31);
    ft_lstadd_back(&head_a, new_node_31);

    t_number *number_32 = (t_number *)malloc(sizeof(t_number));
    number_32->value = 3;
    t_list *new_node_32 = ft_lstnew(number_32);
    ft_lstadd_back(&head_a, new_node_32);

    t_number *number_33 = (t_number *)malloc(sizeof(t_number));
    number_33->value = 4;
    t_list *new_node_33 = ft_lstnew(number_33);
    ft_lstadd_back(&head_a, new_node_33);

    t_number *number_34 = (t_number *)malloc(sizeof(t_number));
    number_34->value = 2;
    t_list *new_node_34 = ft_lstnew(number_34);
    ft_lstadd_back(&head_a, new_node_34);

    t_number *number_35 = (t_number *)malloc(sizeof(t_number));
    number_35->value = 5;
    t_list *new_node_35 = ft_lstnew(number_35);
    ft_lstadd_back(&head_a, new_node_35);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);
    assert(((t_number *)head_a->next->next->next->next->content)->value == 5);

    ft_lstclear(&head_a, free);

    // Test 8: 1 3 4 5 2
    t_number *number_36 = (t_number *)malloc(sizeof(t_number));
    number_36->value = 1;
    t_list *new_node_36 = ft_lstnew(number_36);
    ft_lstadd_back(&head_a, new_node_36);

    t_number *number_37 = (t_number *)malloc(sizeof(t_number));
    number_37->value = 3;
    t_list *new_node_37 = ft_lstnew(number_37);
    ft_lstadd_back(&head_a, new_node_37);

    t_number *number_38 = (t_number *)malloc(sizeof(t_number));
    number_38->value = 4;
    t_list *new_node_38 = ft_lstnew(number_38);
    ft_lstadd_back(&head_a, new_node_38);

    t_number *number_39 = (t_number *)malloc(sizeof(t_number));
    number_39->value = 5;
    t_list *new_node_39 = ft_lstnew(number_39);
    ft_lstadd_back(&head_a, new_node_39);

    t_number *number_40 = (t_number *)malloc(sizeof(t_number));
    number_40->value = 2;
    t_list *new_node_40 = ft_lstnew(number_40);
    ft_lstadd_back(&head_a, new_node_40);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);
    assert(((t_number *)head_a->next->next->next->next->content)->value == 5);

    ft_lstclear(&head_a, free);

    // Test 9: 1 4 2 3 5
    t_number *number_41 = (t_number *)malloc(sizeof(t_number));
    number_41->value = 1;
    t_list *new_node_41 = ft_lstnew(number_41);
    ft_lstadd_back(&head_a, new_node_41);

    t_number *number_42 = (t_number *)malloc(sizeof(t_number));
    number_42->value = 4;
    t_list *new_node_42 = ft_lstnew(number_42);
    ft_lstadd_back(&head_a, new_node_42);

    t_number *number_43 = (t_number *)malloc(sizeof(t_number));
    number_43->value = 2;
    t_list *new_node_43 = ft_lstnew(number_43);
    ft_lstadd_back(&head_a, new_node_43);

    t_number *number_44 = (t_number *)malloc(sizeof(t_number));
    number_44->value = 3;
    t_list *new_node_44 = ft_lstnew(number_44);
    ft_lstadd_back(&head_a, new_node_44);

    t_number *number_45 = (t_number *)malloc(sizeof(t_number));
    number_45->value = 5;
    t_list *new_node_45 = ft_lstnew(number_45);
    ft_lstadd_back(&head_a, new_node_45);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);
    assert(((t_number *)head_a->next->next->next->next->content)->value == 5);

    ft_lstclear(&head_a, free);

    // Test 10: 1 4 2 5 3
    t_number *number_46 = (t_number *)malloc(sizeof(t_number));
    number_46->value = 1;
    t_list *new_node_46 = ft_lstnew(number_46);
    ft_lstadd_back(&head_a, new_node_46);

    t_number *number_47 = (t_number *)malloc(sizeof(t_number));
    number_47->value = 4;
    t_list *new_node_47 = ft_lstnew(number_47);
    ft_lstadd_back(&head_a, new_node_47);

    t_number *number_48 = (t_number *)malloc(sizeof(t_number));
    number_48->value = 2;
    t_list *new_node_48 = ft_lstnew(number_48);
    ft_lstadd_back(&head_a, new_node_48);

    t_number *number_49 = (t_number *)malloc(sizeof(t_number));
    number_49->value = 5;
    t_list *new_node_49 = ft_lstnew(number_49);
    ft_lstadd_back(&head_a, new_node_49);

    t_number *number_50 = (t_number *)malloc(sizeof(t_number));
    number_50->value = 3;
    t_list *new_node_50 = ft_lstnew(number_50);
    ft_lstadd_back(&head_a, new_node_50);

    order_a(head_a);

    assert(((t_number *)head_a->content)->value == 1);
    assert(((t_number *)head_a->next->content)->value == 2);
    assert(((t_number *)head_a->next->next->content)->value == 3);
    assert(((t_number *)head_a->next->next->next->content)->value == 4);
    assert(((t_number *)head_a->next->next->next->next->content)->value == 5);

    ft_lstclear(&head_a, free);
}

void test_order_6()
{
    t_list *head_a;
    head_a = NULL;

    // Test 1: 1 2 3 4 5 6
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

    t_number *number_4 = (t_number *)malloc(sizeof(t_number));
    number_4->value = 4;
    t_list *new_node_4 = ft_lstnew(number_4);
    ft_lstadd_back(&head_a, new_node_4);

    t_number *number_5 = (t_number *)malloc(sizeof(t_number));
    number_5->value = 5;
    t_list *new_node_5 = ft_lstnew(number_5);
    ft_lstadd_back(&head_a, new_node_5);

    t_number *number_6 = (t_number *)malloc(sizeof(t_number));
    number_6->value = 6;
    t_list *new_node_6 = ft_lstnew(number_6);
    ft_lstadd_back(&head_a, new_node_6);

    order_a(head_a);

    ft_lstclear(&head_a, free);
}

int main(void)
{
    test_order_2();
    test_order_3();
    test_order_4();
    test_order_5();
    test_order_6();
    return(0);
}