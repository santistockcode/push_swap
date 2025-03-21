
#include "../../include/push_swap.h"
// calculate size for malloc
int	size_for_malloc(char **argv, int argc)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

// allocate memory


// strlcpy first element


// strlcat + ft_strlen next elements of the string


// return the string

char    *ft_join_spaces(char **argv, int argc)
{
	char    *str;
	int     i;
	int     j;
	int     len;
	int	 	k;

	i = 1;
	len = 0;
	len = size_for_malloc(argv, argc);
	str = (char *)malloc((len + argc) * sizeof(char));
	if (!str)
		return (NULL);
	i = 1;
	j = 0;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			str[k++] = argv[i][j++];
		}
		str[k++] = ' ';
		i++;
	}
	str[k] = '\0';
	return (str);
}