/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:35:01 by rejocic           #+#    #+#             */
/*   Updated: 2018/07/18 18:53:34 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	int				j;
	unsigned char	*str1;
	unsigned char	*str2;

	if (s1 == s2 || n == 0)
		return (0);
	i = 0;
	j = n - 1;
	str1 = ((unsigned char *)s1);
	str2 = ((unsigned char *)s2);
	while (j > 0 && str1[i] == str2[i])
	{
		j--;
		i++;
	}
	return (str1[i] - str2[i]);
}
