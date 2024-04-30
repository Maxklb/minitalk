/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:26:37 by makoch-l          #+#    #+#             */
/*   Updated: 2024/04/30 15:42:07 by makoch-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	check_type(va_list args, const char input)
{
	int				i;

	i = 0;
	if (input == 'c')
		i += print_char(va_arg(args, int));
	else if (input == 's')
		i += print_string(va_arg(args, char *));
	else if (input == 'p')
		i += print_pointer(va_arg(args, unsigned long long));
	else if (input == 'd' || input == 'i')
		i += print_int(va_arg(args, int));
	else if (input == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (input == 'x')
		i += print_hex(va_arg(args, unsigned int), 87);
	else if (input == 'X')
		i += print_hex(va_arg(args, unsigned int), 55);
	else if (input == '%')
		i += print_percent();
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				i;
	int				print_len;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += check_type(args, str[i + 1]);
			i++;
		}
		else
			print_len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

/*int main()
{
	ft_printf("%s","j'aime les pizzas ananas\n");
	ft_printf("Mon entier est : %d\n", 42);
	ft_printf("Mon entier est : %i\n", 42);
	ft_printf("Mon entier non signé est : %u\n", 42);
	ft_printf("%","j'aime les pizzas ananas\n");
	ft_printf("Mon entier en hexadécimal (maj) est : %X\n", 42);
	ft_printf("Mon entier en hexadécimal (min) est : %x\n", 42);
	ft_printf("Mon pointeur est : %p\n", 42);
	ft_printf("Mon caractère est : %c\n", 'c');
	return (0);
}*/