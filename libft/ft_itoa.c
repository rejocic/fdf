/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:33:27 by rejocic           #+#    #+#             */
/*   Updated: 2018/07/18 20:59:15 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int n)
{
	int		len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char			*str;
	static int		len;
	int				tmp;

	len = ft_len(n);
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len--;
	str[len] = tmp % 10 + '0';
	while (tmp /= 10)
	{
		len--;
		str[len] = tmp % 10 + '0';
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
