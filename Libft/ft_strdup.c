/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:05:47 by makoch-l          #+#    #+#             */
/*   Updated: 2023/11/22 01:08:10 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(source) + 1;
	dest = (char *) malloc(size * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, source, size);
	return (dest);
}
