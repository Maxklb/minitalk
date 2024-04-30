/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:05:31 by makoch-l          #+#    #+#             */
/*   Updated: 2024/04/30 15:44:35 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_hex(unsigned int value, int *len)
{
	int				i;
	unsigned int	buffer;
	char			*str;

	i = 0;
	buffer = value;
	while (buffer != 0)
	{
		buffer = buffer / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*len = i - 1;
	return (str);
}

int	print_hex(unsigned int value, int asc)
{
	unsigned int	tempval;
	char			*printout;
	int				i;
	int				*iptr;

	iptr = &i;
	tempval = value;
	printout = create_hex(value, iptr);
	if (!printout)
		return (0);
	while (tempval != 0)
	{
		if ((tempval % 16) < 10)
			printout[i] = (tempval % 16) + 48;
		else
			printout[i] = (tempval % 16) + asc;
		tempval = tempval / 16;
		i--;
	}
	ft_putstr_fd(printout, 1);
	i = ft_strlen(printout);
	free(printout);
	if (value == 0)
		i += print_char('0');
	return (i);
}
