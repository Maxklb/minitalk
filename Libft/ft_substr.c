/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:56:16 by makoch-l          #+#    #+#             */
/*   Updated: 2023/11/29 17:37:48 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *source, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && source[i])
	{
		dest[i] = source[i];
		i++;
	}
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *source, unsigned int start, size_t len)
{
	char	*dest;
	size_t	word_len;
	size_t	string_len;

	word_len = ft_strlen(source);
	string_len = word_len - start;
	if (!source)
		return (NULL);
	if (start >= word_len)
	{
		dest = (char *) malloc(1 * sizeof(char));
		if (!dest)
			return (NULL);
		*dest = '\0';
		return (dest);
	}
	if (len < string_len)
		string_len = len;
	dest = (char *) malloc((string_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest = ft_strncpy(dest, (char *) source + start, string_len);
	dest[string_len] = '\0';
	return (dest);
}
