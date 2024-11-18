/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <afantune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:33:37 by afantune          #+#    #+#             */
/*   Updated: 2024/11/14 15:25:18 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_format(va_list args, const char *format)
{
	int	i;

	i = 0;
	while (*format)
	{
		if (*format == '%')
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
