/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:26:38 by rejocic           #+#    #+#             */
/*   Updated: 2018/07/16 12:41:37 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = len - 1;
	if (((char *)src) < ((char *)dst))
	{
		while (j >= 0)
		{
			((char *)dst)[j] = ((char *)src)[j];
			j--;
		}
		return (dst);
	}
	while (i < len)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
