/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:46:24 by makoch-l          #+#    #+#             */
/*   Updated: 2024/05/03 15:04:13 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	send_sig(int pid, unsigned char character)
{
	unsigned char	buff;
	int				i;

	i = 8;
	buff = character;
	while (i > 0)
	{
		i--;
		buff = character >> i;
		if (buff % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

int	main(int argc, char *argv[])
{
	int		client_id;
	int		i;
	char	*str;

	client_id = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	if (argc != 3)
	{
		ft_printf("Number of parameters is incorrect");
		exit(0);
	}
	while (str[i])
	{
		send_sig(client_id, str[i]);
		i++;
	}
	send_sig(client_id, '\0');
	return (0);
}
