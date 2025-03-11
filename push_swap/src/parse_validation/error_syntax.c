#include "../../include/push_swap.h"


int error_syntax(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    if (str[i] == '-' || ft_isdigit(str[i]))
        i++;
    else
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}