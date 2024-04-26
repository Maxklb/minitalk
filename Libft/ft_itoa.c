/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:30:53 by makoch-l          #+#    #+#             */
/*   Updated: 2023/11/22 18:46:32 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_size(long num)
{
	int	i;

	i = 0;
	if (num == 0)
		i++;
	if (num < 0)
	{
		num = -num;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*val;
	long	nb;
	size_t	length;

	nb = n;
	length = num_size(n);
	val = malloc(sizeof(char) * (length + 1));
	if (!val)
		return (NULL);
	val[length--] = 0;
	if (n == 0)
		val[0] = '0';
	if (nb < 0)
	{
		val[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		val[length--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (val);
}
