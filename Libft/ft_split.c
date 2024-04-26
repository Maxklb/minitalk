/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:32:21 by makoch-l          #+#    #+#             */
/*   Updated: 2023/11/27 14:47:11 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *s, char c)
{
	size_t	words;
	int		state;

	words = 0;
	state = 1;
	while (s && *s)
	{
		if (*s == c)
			state = 1;
		else if (state == 1)
		{
			words++;
			state = 0;
		}
		s++;
	}
	return (words);
}

static size_t	ft_word_length(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	return (i);
}

static char	**free_tab(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	size_t	index;
	size_t	i;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!tab)
		return (NULL);
	index = 0;
	while (ft_word_count(s, c))
	{
		while (*s == c)
			s++;
		tab[index] = malloc(sizeof(char) * (ft_word_length(s, c) + 1));
		if (!tab[index])
			return (free_tab(tab, index));
		i = 0;
		while (*s && (*s != c))
			tab[index][i++] = *s++;
		tab[index][i] = 0;
		index++;
	}
	tab[index] = 0;
	return (tab);
}

/*#include <stdio.h>

int main(void)
{
	const char *input_string = "test NOSNFS --459w5 949wm    d";
	char **result;

	result = ft_split(input_string, ' ');

	if (result)
	{
		for (int i = 0; result[i] != NULL; i++)
			printf("Mot : %s\n", result[i]);
		for (int i = 0; result[i] != NULL; i++)
			free(result[i]);
		free(result);
	}
	else
		printf("Marche pas\n");
	return 0;
}*/