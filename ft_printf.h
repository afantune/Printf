/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afantune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:32:34 by afantune          #+#    #+#             */
/*   Updated: 2024/11/12 14:37:24 by afantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include "Libft/libft.h"

int		ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		ft_char_conversion(va_list args);
int		ft_string_conversion(va_list args);
int		ft_pointer_conversion(va_list args);
int		ft_int_conversion(va_list args);
int		ft_unsigned_conversion(va_list args);
int		ft_lowerhex_conversion(va_list args);
int		ft_upperhex_conversion(va_list args);
int		ft_percent_conversion(void);
int		ft_putnbr(int n);
int		ft_putnbr_base(unsigned long n, char *base);
int		ft_format(char specifier, va_list args);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);

#endif
