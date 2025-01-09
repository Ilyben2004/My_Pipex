/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putrevstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:46:57 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/11 10:47:57 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putrevstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
		count += write(1, &str[i--], 1);
	return (count);
}
