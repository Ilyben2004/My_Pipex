/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadersse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:23:05 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/11 11:14:55 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadresse(unsigned long number)
{
	int		count;
	int		i;
	char	*str;
	char	*base;

	if (!number)
		return (write(1, "(nil)", 5));
	str = (char *) malloc (hexsize(number) + 1);
	if (!str)
		return (0);
	i = 0;
	count = 0;
	base = "0123456789abcdef";
	count += write(1, "0x", 2);
	while (number > 0)
	{
		str[i++] = base[number % 16];
		number /= 16;
	}
	str[i] = 0;
	count += ft_putrevstr(str);
	free (str);
	return (count);
}
