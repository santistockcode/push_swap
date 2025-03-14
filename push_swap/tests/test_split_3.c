#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "./../include/push_swap.h"


int main(void)
{
    
    // Test with limit cases
    char input2[] = "0 -1 2147483647 -2147483648";
    char **result2 = ft_split_ps(input2);
    
    // Check if the split is correct
    int num2 = atoi(result2[0]);
    assert(num2 == 0);
    
    num2 = atoi(result2[1]);
    assert(num2 == -1);
    
    num2 = atoi(result2[2]);
    assert(num2 == 2147483647);
    
    num2 = atoi(result2[3]);
    assert(num2 == -2147483648);
    
    // Free the allocated memory
    for (int i = 0; i < 4; i++) {
        free(result2[i]);
    }
    free(result2);
    
    return 0;
}