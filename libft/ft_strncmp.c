/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:48:48 by rejocic           #+#    #+#             */
/*   Updated: 2018/07/15 21:05:11 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = ((unsigned char *)s1);
	str2 = ((unsigned char *)s2);
	while ((str1[i] != '\0' || str2[i] != '\0') && (n > 0))
	{
		if (str1[i] < str2[i] || str1[i] > str2[i])
			return (str1[i] - str2[i]);
		i++;
		n--;
	}
	return (0);
}
