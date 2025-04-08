#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "../libft/include/libft.h"

typedef struct t_stacks
{
    t_list	*a_head;
    t_list	*b_head;
}	t_stacks;

// swap a
void    sa(t_stacks *stacks);

// swap b
void    sb(t_stacks *stacks);

// swap a and  swap b
void   ss(t_stacks *stacks);

// // push a
void    pa(t_stacks *stacks);

// push b
void    pb(t_stacks *stacks);

// // rotate a
void    ra(t_stacks *stacks);

// // rotate b
void    rb(t_stacks *stacks);

// // rotate a and rotate b
void    rr(t_stacks *stacks);

// // reverse rotate a
void    rra(t_stacks *stacks);

// // reverse rotate b
void    rrb(t_stacks *stacks);

// // reverse rotate a and reverse rotate b
void    rrr(t_stacks *stacks);

void ft_swap(t_list *a, t_list *b);

#endif