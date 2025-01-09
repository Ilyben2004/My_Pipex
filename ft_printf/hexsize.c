/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:17:53 by ibennaje          #+#    #+#             */
/*   Updated: 2024/12/11 10:20:20 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexsize(unsigned long test)
{
	int	count;

	count = 0;
	if (test == 0)
		return (1);
	while (test > 0)
	{
		count++;
		test /= 16;
	}
	return (count);
}
