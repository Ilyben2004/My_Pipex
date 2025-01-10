/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:33:39 by ibennaje          #+#    #+#             */
/*   Updated: 2025/01/10 10:14:05 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		higheroverlap;
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (NULL);
	if (src == dst)
		return ((void *) src);
	higheroverlap = dst > src;
	while (len > 0)
	{
		if (higheroverlap)
			*((unsigned char *)dst + len - 1) = *((unsigned char *)src + len
					- 1);
		else
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i++;
		}
		len--;
	}
	return (dst);
}
