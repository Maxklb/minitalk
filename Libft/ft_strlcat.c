/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:13:49 by makoch-l          #+#    #+#             */
/*   Updated: 2023/11/22 17:37:51 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		length;

	length = ft_strlen(dst);
	i = 0;
	if (!dstsize || dstsize < length + 1)
		return (dstsize + ft_strlen(src));
	while (length + i + 1 < dstsize && src[i])
	{
		dst[length + i] = src[i];
		i++;
	}
	dst[length + i] = 0;
	return (length + ft_strlen(src));
}
