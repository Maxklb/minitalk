/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:20:44 by makoch-l          #+#    #+#             */
/*   Updated: 2023/11/13 16:27:31 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	length;
	size_t	i;

	length = ft_strlen(s);
	i = 0;
	if (!f || !s)
		return ;
	while (i < length)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
