/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:18:56 by rejocic           #+#    #+#             */
/*   Updated: 2018/09/07 12:59:13 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		res_start(char **res, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*res)[i] && (*res)[i] != '\n')
		i++;
	if ((*res)[i] == '\n')
	{
		(*res)[i] = '\0';
		if ((*line = ft_strdup(*res)) == NULL)
			return (-1);
		tmp = *res;
		if ((*res = ft_strdup((*res) + (i + 1))) == NULL)
			return (-1);
		free(tmp);
		return (1);
	}
	return (0);
}

int		res_end(char **res, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*res)[i] && (*res)[i] != '\n')
		i++;
	if ((*res)[i] == '\n')
	{
		(*res)[i] = '\0';
		if ((*line = ft_strdup(*res)) == NULL)
			return (-1);
		tmp = *res;
		if ((*res = ft_strdup((*res) + (i + 1))) == NULL)
			return (-1);
		free(tmp);
		return (1);
	}
	else
	{
		*line = *res;
		*res = NULL;
		return (1);
	}
	return (0);
}

int		if_newline(char **res, char **line, char *str, int i)
{
	char	*tmp;

	(str)[i] = '\0';
	if ((*line = ft_strjoin(*res, str)) == NULL)
		return (-1);
	tmp = *res;
	if ((*res = ft_strdup((str) + (i + 1))) == NULL)
		return (-1);
	free(tmp);
	return (1);
}

int		readfunc(char **res, char **line, char *str, int r)
{
	int		i;
	char	*tmp;

	i = 0;
	(str)[r] = '\0';
	while ((str)[i] != '\n' && i < r)
		i++;
	if ((str)[i] == '\n')
		return (if_newline(res, line, str, i));
	else
	{
		tmp = *res;
		if ((*res = ft_strjoin(*res, str)) == NULL)
			return (-1);
		free(tmp);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			r;
	char		*str;
	static char	*res[MAX_FD];

	if (fd < 0 || line == NULL || fd > MAX_FD)
		return (-1);
	if (res[fd] == NULL)
		res[fd] = ft_strnew(0);
	if (res[fd] != '\0')
		if ((res_start(&res[fd], line)) == 1)
			return (1);
	if ((str = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	while ((r = read(fd, str, BUFF_SIZE)) > 0)
		if ((readfunc(&res[fd], line, str, r)) == 1)
		{
			free(str);
			return (1);
		}
	free(str);
	if (r == 0 && res[fd][r] != '\0')
		return (res_end(&res[fd], line));
	if (r < 0)
		return (-1);
	return (0);
}
