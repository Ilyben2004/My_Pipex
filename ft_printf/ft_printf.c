/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:02:40 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/11 16:12:20 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printer(va_list ptr, char c, int *percentage_found)
{
	*percentage_found = 1;
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd((int)va_arg(ptr, int), 1));
	else if (c == 'u')
		return (ft_putnbr_fd((unsigned int)va_arg(ptr, unsigned int), 1));
	else if (c == 'c')
		return (ft_putchar_fd((int)va_arg(ptr, int), 1));
	else if (c == 's')
		return (ft_putstr_fd((char *)va_arg(ptr, char *), 1));
	else if (c == 'x' || c == 'X')
		return (ft_puthex((unsigned int)va_arg(ptr, unsigned int), c));
	else if (c == 'p')
		return (ft_putadresse((unsigned long) va_arg(ptr, void *)));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else
	{
		if (c != 0)
			return (ft_putchar_fd('%', 1) + ft_putchar_fd(c, 1));
		else
			return (ft_putchar_fd('%', 1));
	}
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		percentage_found;
	int		size;
	int		i;
	va_list	ptr;

	if (!format)
		return (-1);
	size = ft_strlen(format);
	va_start(ptr, format);
	i = -1;
	count = 0;
	percentage_found = 0;
	while (++i < size)
	{
		if (format[i] != '%')
			count = count + ft_putchar_fd(format[i], 1);
		else if (format[i] == '%')
		{
			if (!(format[i + 1]) && !percentage_found)
				return (va_end(ptr), -1);
			count += printer(ptr, format[(i++) + 1], &percentage_found);
		}
	}
	return (va_end(ptr), count);
}
