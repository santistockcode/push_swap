/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:45:46 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/07 18:11:54 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

long	ft_atol(const char *str)
{
	long	n;
	int		flag;
	long	i;

	n = 0;
	flag = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			flag = -flag;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * flag);
}
