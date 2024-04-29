/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:45:00 by makoch-l          #+#    #+#             */
/*   Updated: 2023/11/22 15:47:19 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	if (length <= 0)
		return (0);
	while (first[i] && second[i] && i < length)
	{
		if (first[i] != second[i])
			return ((unsigned char) first[i] - (unsigned char) second[i]);
		i++;
	}
	if (!diff && i < length)
		diff = (unsigned char) first[i] - (unsigned char) second[i];
	return (diff);
}
