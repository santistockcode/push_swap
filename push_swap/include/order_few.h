// this function orders a list of three elements
void order_three(t_list *a_head);

// this function orders a list of 5 or less elements
void order_five(t_list *a_head);

// Pushes the minimum element from a to b
void	push_min_to_b(t_stacks *stacks);

// Rotates A until a specific number is on top (used before pushing to b)
void	rotate_until_top(t_list **a_head_ref, int number);