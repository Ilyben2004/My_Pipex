/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:35:48 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/11 10:46:00 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int number, char c)
{
	char	*base;
	char	*str;
	int		i;
	int		size;
	int		count;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	size = hexsize(number);
	str = (char *) malloc(size + 1);
	if (!str)
		return (0);
	while (size > i)
	{
		str[i++] = base[number % 16];
		number /= 16;
	}
	str[i] = 0;
	count = ft_putrevstr(str);
	free(str);
	return (count);
}
