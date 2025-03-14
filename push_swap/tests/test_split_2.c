#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "./../include/push_swap.h"

int main(void)
{
        char input[] = "  1 2 3 4 5 6 7 8 9 10  11 12 13 14 15 16 17 18 19 20";
        char **result = ft_split_ps(input);
        
        // Check if the split is correct
        for (int i = 0; i < 20; i++) {
            int num = atoi(result[i]);
            assert(num == i + 1);
        }
        
        // Free the allocated memory
        for (int i = 0; i < 20; i++) {
            free(result[i]);
        }
        free(result);
        
        return 0;
}