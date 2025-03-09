#include "../include/push_swap.h"


int main(int argc, char **argv) {
    
    // si me pasan un solo argumento o una cadena vacía
    if (argc < 2 || (argc == 2 && !argv[1][0])) {
        return (1);
    }
    if (argc == 2) {
        argv  = ft_split_ps(argv[1]);
    }
    // validate char **argv
    write(1, "Split made by copilot: ", 6);
    for (int i = 0; argv[i]; i++) {
        write(1, argv[i], ft_strlen(argv[i]));
        write(1, " ", 1);
    }
    return (0);
}