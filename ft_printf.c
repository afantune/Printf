/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:33:37 by afantune          #+#    #+#             */
/*   Updated: 2024/11/13 13:01:42 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_specifier(char c)
{
	if (c == '%' || c == 's' || c == 'd' || c == 'i' || c == 'c' || c == 'p'
		|| c == 'x' || c == 'X' || c == 'u')
		return (1);
	return (0);
}

static int	process_format(va_list args, const char *format)
{
	int	i;

	i = 0;
	while (*format)
	{
		if (*format == '%' && is_specifier(*(format + 1)))
		{
			format++;
			if (*format == '\0')
				return (i);
			i += ft_format(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			i++;
		}
		format++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	if (!format)
	{
		return (-1);
	}
	va_start(args, format);
	i = process_format(args, format);
	va_end(args);
	return (i);
}
