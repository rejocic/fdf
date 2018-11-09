/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:45:15 by rejocic           #+#    #+#             */
/*   Updated: 2018/09/28 19:46:37 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wc(char const *s, char c)
{
	int		i;
	int		wc;

	i = 0;
	wc = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			wc++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		i++;
	}
	return (wc);
}

static int		ft_word_len(char const *s, int start, char c)
{
	int		len;

	len = 0;
	while (s[start] != '\0')
	{
		while (s[start] == c)
			start++;
		while (s[start] != c && s[start])
		{
			start++;
			len++;
		}
		return (len);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	int				i;
	int				j;
	static int		wc;
	char			**arr;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	wc = ft_wc(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (wc + 1))))
		return (NULL);
	while (j < wc && s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		arr[j] = ft_strsub(s, i, ft_word_len(s, i, c));
		if (arr[j] == NULL)
			return (NULL);
		i = i + ft_word_len(s, i, c);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
