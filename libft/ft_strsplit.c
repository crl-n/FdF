/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:19:11 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/13 20:54:01 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	arr_size(char const *s, char c)
{
	size_t	size;
	int		new;

	size = 0;
	new = 1;
	while (*s)
	{
		if (*s == c)
			new = 1;
		else
		{
			if (new == 1)
				size++;
			new = 0;
		}
		s++;
	}
	return (size + 1);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static const char	*goto_next_word(const char *s, char c)
{
	while (*s != c)
		s++;
	while (*s == c)
		s++;
	return (s);
}

static char	**create_arr(char const *s, char c, size_t size, char **arr)
{
	size_t	i;
	size_t	len;
	char	*word;

	i = 0;
	while (*s == c)
		s++;
	while (i < size - 1)
	{
		len = word_len(s, c);
		word = (char *) malloc((len + 1) * sizeof (char));
		if (!word)
		{
			while (i--)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		ft_strncpy(word, s, len);
		word[len] = '\0';
		arr[i++] = word;
		s = goto_next_word(s, c);
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	size;

	if (!s)
		return (NULL);
	size = arr_size(s, c);
	arr = (char **) malloc(size * sizeof (char *));
	if (!arr)
		return (NULL);
	arr = create_arr(s, c, size, arr);
	return (arr);
}
