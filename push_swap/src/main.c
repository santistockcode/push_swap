#include "../include/push_swap.h"


int main(int argc, char **argv) {
    
    // si me pasan un solo argumento o una cadena vacía
    if (argc < 2 || (argc == 2 && !argv[1][0])) {
        return (1);
    }
    if (argc == 2) {
        argv  = ft_split_ps(argv[1]);        
    }
    if (argv && !valid_input_and_list(argv)) {
        free_argv(argv);
        return (print_error(), 1);
    }
    return (0);
}