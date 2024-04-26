/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:19:57 by makoch-l          #+#    #+#             */
/*   Updated: 2023/11/23 17:31:17 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*val;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[j] && is_charset(s1[j], set))
		j++;
	k = ft_strlen(s1);
	while (k > j && is_charset(s1[k - 1], set))
		k--;
	val = malloc(sizeof(char) * ((k - j) + 1));
	if (!val)
		return (NULL);
	while (j < k)
		val[i++] = s1[j++];
	val[i] = 0;
	return (val);
}
