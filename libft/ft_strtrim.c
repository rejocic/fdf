/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:21:03 by rejocic           #+#    #+#             */
/*   Updated: 2018/07/17 16:31:39 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i[2];
	size_t	len;
	char	*str;

	i[0] = 0;
	i[1] = 0;
	if (s == NULL)
		return (NULL);
	while (s[i[0]] == ' ' || s[i[0]] == '\n' || s[i[0]] == '\t')
		i[0]++;
	if (s[i[0]] == '\0')
		return ((char *)ft_memalloc(sizeof(char)));
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	if ((str = (char *)malloc(sizeof(char) * (len - i[0]) + 2)) == NULL)
		return (NULL);
	while (i[0] <= len)
	{
		str[i[1]] = s[i[0]];
		i[0]++;
		i[1]++;
	}
	str[i[1]] = '\0';
	return (str);
}
