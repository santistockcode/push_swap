/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:11:02 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/07 18:15:12 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	size_for_malloc(char **argv, int argc)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	size = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			size++;
			j++;
		}
		i++;
	}
	return (size);
}

char	*ft_join_spaces(char **argv, int argc)
{
	char	*ret_str;
	int		i;
	int		j;
	int		len;
	int		k;

	len = size_for_malloc(argv, argc);
	ret_str = (char *)malloc((len + argc) * sizeof(char));
	if (!ret_str)
		return (NULL);
	i = 1;
	j = 0;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			ret_str[k++] = argv[i][j++];
		}
		ret_str[k++] = ' ';
		i++;
	}
	ret_str[k] = '\0';
	return (ret_str);
}
