/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:46:22 by makoch-l          #+#    #+#             */
/*   Updated: 2024/05/02 20:51:20 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	sig_handle(int sig)
{
	static unsigned char	buff;
	static int				i;

	buff |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", buff);
		i = 0;
		buff = 0;
	}
	else
		buff <<= 1;
}

int main(void)
{
	ft_printf("Client ID PID is : %i\n", getpid());
	signal(SIGUSR2, sig_handle);
	signal(SIGUSR1, sig_handle);
	while (1)
		pause();
	return (0);
}
