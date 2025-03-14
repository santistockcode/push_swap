#include "../include/push_swap.h"


int main(int argc, char **argv) {
    
    t_list *a;
    // si me pasan un solo argumento o una cadena vacía
    if (argc < 2 || (argc == 2 && !argv[1][0])) {
        return (1);
    }
    if (argc == 2) {
        argv  = ft_split_ps(argv[1]);        
    }
    if (argv) {
        a = valid_input_and_list(argv);
        if (!a)
            return (free_argv(argv), print_error(), 1);
        print_list(a);
    }
    return (0);
}