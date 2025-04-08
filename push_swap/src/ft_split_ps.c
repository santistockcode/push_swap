/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:15:41 by saalarco          #+#    #+#             */
/*   Updated: 2025/04/07 18:15:55 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// CHULETA static  char    *get_next_word(char *s, char c)
// siendo char *s la cadena completa y c el delimitador
// declarar cursor (static) = 0, len = 0, i = 0;
// avanzar cursor en s mientras estemos en el delimitador
// avanzar len si s[cursor + len] no se el delimitador (no avanza el cursor)
// reservar espacio next_word para len (para la palabra) con malloc y proteger
// ahora sí avanzar cursor e ir rellenando next_word[i++] con s[cursor++]
// null terminate next_word
// devolver next_word

int	ft_issspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	countw(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] && ft_issspace(str[i]))
		i++;
	while (str[i])
	{
		if (!ft_issspace(str[i]))
		{
			n++;
			while (str[i] && !ft_issspace(str[i]))
				i++;
		}
		while (str[i] && ft_issspace(str[i]))
			i++;
	}
	return (n);
}

// this function returns allocated space of len with contnet of next word 
// ACTHUNG: cursor static only works because in push swap we call this function 
// just once
char	*alloc_word(char	*str)
{
	static int	cursor;
	int			i;
	int			l;
	char		*result;

	l = 0;
	i = 0;
	while (str[cursor] && ft_issspace(str[cursor]))
		cursor++;
	while (str[cursor + l] && !ft_issspace(str[cursor + l]))
		l++;
	result = (char *) malloc ((l + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (str[cursor] && !ft_issspace(str[cursor]))
		result[i++] = str[cursor++];
	result[i] = '\0';
	return (result);
}

// This function splits the string into an array of strings representing numbers
// As standard practice in arrays of pointers, ends with a 
// NULL pointer as centinel
// Each word of course ends in '\0'

char	**ft_split_ps(char *str)
{
	int		wordsn;
	char	**result;
	int		i;

	i = 0;
	wordsn = countw(str);
	result = (char **) malloc((wordsn + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (i < wordsn)
	{
		result[i] = alloc_word(str);
		if (result[i] == NULL)
		{
			while (i >= 0)
				free(result[i--]);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = 0;
	return (result);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (0);
// 	printf("WORDS: %d", countw(argv[1]));
// 	return (1);
// }