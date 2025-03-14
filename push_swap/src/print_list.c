#include <stdio.h>
#include "../include/push_swap.h"


void print_list(t_list *head) {
    t_list *current = head;
    while (current != NULL) {
        t_number *number = (t_number *)current->content;
        printf("Value: %d, Index: %d\n", number->value, number->index);
        current = current->next;
    }
}
