#include "../include/push_swap.h"

int main(int argc, char **argv) {

    if (argc < 2) {
        // 
        return (1);
    }
    // case 1: ./push_swap "1 2 3 4 5"
    if (argc > 2) {
    
    // case 2: ./push_swap 1 2 3 4 5
    } else if (argc == 2) {
        // TODO: Include ft_strtol in libft
        long num = ft_strtol(argv[1], NULL, 10);
        if (num == 0) {
            printf("Invalid input\n");
            return 1;
        }
        // Use the parsed number 'num' here
        // ...
    } else {
        // Code for argc == 1
        // ...
    }

    return 0;
}