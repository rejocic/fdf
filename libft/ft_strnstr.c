/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:10:12 by rejocic           #+#    #+#             */
/*   Updated: 2018/07/15 20:51:31 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	size_t	needlen;

	i = 0;
	j = 0;
	needlen = ft_strlen(needle);
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && (int)(len - needlen) >= 0)
	{
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		j = 0;
		i++;
		len--;
	}
	return (NULL);
}
