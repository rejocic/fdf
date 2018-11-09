/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:37:22 by rejocic           #+#    #+#             */
/*   Updated: 2018/07/17 16:54:15 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((str = (char *)malloc(sizeof(char) * (len1 + len2 + 1))) == NULL)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1] != '\0')
	{
		str[len1] = s1[len1];
		len1++;
	}
	while (s2[len2] != '\0')
	{
		str[len1] = s2[len2];
		len1++;
		len2++;
	}
	str[len1] = '\0';
	return (str);
}
