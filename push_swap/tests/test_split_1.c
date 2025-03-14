#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "./../include/push_swap.h"

int main(void)
{
    char *empty_string = "";
    char **result = ft_split_ps(empty_string);
    assert(*result == NULL);
    free(result);
    return(0);
}