#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include "./../include/push_swap.h"


// UTILS FOR TESTS

/* allocate & pre‑fill a t_number with just the value field */
static t_number *num_new(int v)
{
    t_number *n = malloc(sizeof(t_number));
    if (!n)
        return (NULL);
    memset(n, 0, sizeof(t_number));
    n->value = v;
    return (n);
}

/* convert list to int array (values only) */
// static void list_to_arr(t_list *lst, int *out, int count)
// {
//     for (int i = 0; i < count && lst; ++i)
//     {
//         out[i] = ((t_number *)lst->content)->value;
//         lst = lst->next;
//     }
// }

// /* qsort comparison helper */
// static int cmp_int(const void *a, const void *b)
// {
//     return (*(const int *)a - *(const int *)b);
// }



// static void test_push_from_a_to_b(void)
// {
//     int src_vals[6] = {4, 1, 3, 2, 6, 5};
//     t_list *a = NULL;
//     t_list *b = NULL;

//     for (int i = 0; i < 6; ++i)
//         ft_lstadd_back(&a, ft_lstnew(num_new(src_vals[i])));

//     /* 2. run the function under test */
//     push_from_a_to_b(&a, &b);  

//     /* 3. basic post‑conditions */
//     assert(ft_lstsize(a) == 3);        
//     assert(ft_lstsize(b) == 3);

//     /* 4. all numbers are still present (no dup / loss) */
//     int merged[6];
//     list_to_arr(a, merged, 3);
//     list_to_arr(b, merged + 3, 3);
//     qsort(merged, 6, sizeof(int), cmp_int);

//     int expect[6] = {1, 2, 3, 4, 5, 6};
//     for (int i = 0; i < 6; ++i)
//         assert(merged[i] == expect[i]);

//     printf("A");
//     print_list(a);
//     printf("B");
//     print_list(b);

//     ft_lstclear(&a, free);
//     ft_lstclear(&b, free);

//     printf("✓ test_push_from_a_to_b passed\n");
// }


static int expected_target_value(int v, t_list *b)
{
    t_list *iter = b;
    int     best = INT_MIN;
    int     max  = INT_MIN;

    while (iter)
    {
        int val = ((t_number *)iter->content)->value;
        if (val < v && val > best)
            best = val;
        if (val > max)
            max = val;
        iter = iter->next;
    }
    if (best == INT_MIN)
        return (max);
    return (best);
}

// chatgpt dixit
static void test_set_target_a(void)
{
    srand(42);                        /* deterministic randomness   */

    for (int run = 0; run < 10; ++run)
    {
        const int SIZE_A = 10 + rand() % 10;   /* 10..19 */
        const int SIZE_B = 10 + rand() % 10;   /* 10..19 */
        const int TOTAL   = SIZE_A + SIZE_B;
        int      pool[TOTAL];

        /* --- build a pool of unique random ints ------------------ */
        int count = 0;
        while (count < TOTAL)
        {
            int candidate = (rand() % 20000) - 10000;  /* range -10k..10k */
            // int candidate = (rand() % 200) - 100;  /* range -10k..10k */

            int dup = 0;
            for (int i = 0; i < count; ++i)
                if (pool[i] == candidate)
                    dup = 1;
            if (!dup)
                pool[count++] = candidate;
        }

        /* --- populate stacks A and B ----------------------------- */
        t_list *a = NULL;
        t_list *b = NULL;

        for (int i = 0; i < SIZE_A; ++i)
            ft_lstadd_back(&a, ft_lstnew(num_new(pool[i])));

        for (int i = 0; i < SIZE_B; ++i)
            ft_lstadd_back(&b, ft_lstnew(num_new(pool[SIZE_A + i])));

        update_indexes(a);
        update_indexes(b);
        /* --- print complete list --------------------------------- */
        // printf("---------------------------------A\n");
        // print_list(a);
        // printf("---------------------------------B\n");
        // print_list(b);

        /* --- call function under test ---------------------------- */
        set_target_a(a, b);

        /* --- print complete list --------------------------------- */

        /* --- verify every node in A has the correct target ------- */
        t_list *iter = a;
        while (iter)
        {
            t_number *nbr   = (t_number *)iter->content;
            assert(nbr->target_node != NULL);

            int expect = expected_target_value(nbr->value, b);
            // printf("\nFor numa: %d ---> ", nbr->value);
            // printf("Numa: %d", expect);
            int actual = ((t_number *)nbr->target_node->content)->value;
            assert(expect == actual);
            iter = iter->next;
        }

        /* --- clean‑up ------------------------------------------- */
        ft_lstclear(&a, free);
        ft_lstclear(&b, free);
    }
}

/* positive index → ra/rb  |  negative index → rra/rrb */
static int rotate_cost(int idx, int size)
{
    return (idx <= size / 2) ? idx : idx - size;
}

static int total_overlap(int cost_a, int cost_b)
{
    if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
        return (abs(cost_a) > abs(cost_b) ? abs(cost_a) : abs(cost_b));
    return (abs(cost_a) + abs(cost_b));
}

/* --------------------------- the test ----------------------------- */

static void test_calculate_price(void)
{
    srand(99);

    for (int run = 0; run < 30; ++run)
    {
        int size_a = 4 + rand() % 5;  /* 4..8  */
        int size_b = 4 + rand() % 5;  /* 4..8  */
        int total  = size_a + size_b;
        int pool[32];

        /* build unique random pool */
        int used = 0;
        while (used < total)
        {
            int n = (rand() % 20000) - 10000;
            int dup = 0;
            for (int i = 0; i < used; ++i)
                if (pool[i] == n)
                    dup = 1;
            if (!dup) pool[used++] = n;
        }

        /* build stacks */
        t_list *a = NULL;
        t_list *b = NULL;
        for (int i = 0; i < size_a; ++i)
            ft_lstadd_back(&a, ft_lstnew(num_new(pool[i])));
        for (int i = 0; i < size_b; ++i)
            ft_lstadd_back(&b, ft_lstnew(num_new(pool[size_a + i])));

        /* metadata + calls under test */
        update_indexes(a);
        update_indexes(b);
        set_target_a(a, b);
        calculate_price(a, b);

        /* validate every node in A */
        t_list *iter = a;
        while (iter)
        {
            t_number *nbr    = (t_number *)iter->content;
            t_list   *target = nbr->target_node;
            assert(target);             /* target must be set */

            int cost_a  = rotate_cost(nbr->index,
                                      size_a);
            int cost_b  = rotate_cost(((t_number *)target->content)->index,
                                      size_b);
            int expect_total = total_overlap(cost_a, cost_b);

            /* individual costs */
            assert(nbr->price_a == cost_a);
            assert(nbr->price_b == cost_b);

            /* total with overlap */
            assert(nbr->total_price == expect_total);

            iter = iter->next;
        }

        ft_lstclear(&a, free);
        ft_lstclear(&b, free);
    }

}


static void test_mark_cheapest(void)
{
    srand(99);

    for (int run = 0; run < 8; ++run)
    {
        int size_a = 4 + rand() % 5;  /* 4..8  */
        int size_b = 4 + rand() % 5;  /* 4..8  */
        int total  = size_a + size_b;
        int pool[32];

        /* build unique random pool */
        int used = 0;
        while (used < total)
        {
            int n = (rand() % 20000) - 10000;
            int dup = 0;
            for (int i = 0; i < used; ++i)
                if (pool[i] == n)
                    dup = 1;
            if (!dup) pool[used++] = n;
        }

        /* build stacks */
        t_list *a = NULL;
        t_list *b = NULL;
        for (int i = 0; i < size_a; ++i)
            ft_lstadd_back(&a, ft_lstnew(num_new(pool[i])));
        for (int i = 0; i < size_b; ++i)
            ft_lstadd_back(&b, ft_lstnew(num_new(pool[size_a + i])));

        /* metadata + calls under test */
        update_indexes(a);
        update_indexes(b);
        set_target_a(a, b);
        calculate_price(a, b);
        mark_cheapest(a);

        /* validate every node in A */
        t_list *iter = a;
            t_list *iter2 = a;
        int marked = 0;
        int min = INT_MAX;
        int val_num = 0;
        while (iter)
        {
            t_number *nbr    = (t_number *)iter->content;
            t_list   *target = nbr->target_node;
            assert(target);             /* target must be set */

            int cost_a  = rotate_cost(nbr->index,
                                      size_a);
            int cost_b  = rotate_cost(((t_number *)target->content)->index,
                                      size_b);
            int expect_total = total_overlap(cost_a, cost_b);

            /* individual costs */
            assert(nbr->price_a == cost_a);
            assert(nbr->price_b == cost_b);
            assert(nbr->total_price == expect_total);
            if (nbr->is_cheapest == 1)
            {
                val_num = nbr->value;
                marked++;
            }
            if (nbr->total_price < min)
                min = nbr->total_price;

            iter = iter->next;
        }
        assert (marked == 1);
        
        while (iter2)
        {
            t_number *nbr2    = (t_number *)iter2->content;
            if (nbr2->value == val_num)
            {
                assert(nbr2->total_price == min);
            }

            iter2 = iter2->next;
        }

        ft_lstclear(&a, free);
        ft_lstclear(&b, free);
    }

}

int main(void)
{
    // test_push_from_a_to_b();
    // test_do_cheapest_move_a_to_b();
    test_set_target_a();
    test_calculate_price();
    test_mark_cheapest();
    return(0);
}