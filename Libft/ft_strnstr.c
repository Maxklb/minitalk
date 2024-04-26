/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:42:23 by makoch-l          #+#    #+#             */
/*   Updated: 2023/11/20 15:23:22 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t length)
{
	size_t	needle_length;
	size_t	i;
	size_t	j;

	needle_length = ft_strlen(needle);
	if (!needle_length)
		return ((char *) haystack);
	i = 0;
	while (i < length && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < length)
		{
			j++;
			if (j == needle_length)
				return ((char *) haystack + i);
		}
		i++;
	}
	return (NULL);
}
