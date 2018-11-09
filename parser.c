/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 21:15:25 by rejocic           #+#    #+#             */
/*   Updated: 2018/09/10 21:15:27 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		initialread(char *line, t_mlx *mlx)
{
	int		k;

	k = 0;
	mlx->cords.max_x = 0;
	mlx->cords.max_y = 0;
	mlx->wc = ft_word_count(line, ' ');
	mlx->chararr = ft_strsplit(line, ' ');
	while (mlx->chararr[mlx->cords.max_x] != NULL)
		mlx->cords.max_x++;
	mlx->introw = (int *)malloc(sizeof(int) * mlx->cords.max_x);
	while (k < mlx->cords.max_x)
	{
		mlx->introw[k] = ft_atoi(mlx->chararr[k]);
		k++;
	}
	k = 0;
	while (mlx->chararr[k])
		free(mlx->chararr[k++]);
	free(line);
	free(mlx->chararr);
	mlx->intarr = (int **)malloc(sizeof(int *) * (mlx->cords.max_y + 1));
	mlx->intarr[mlx->cords.max_y++] = mlx->introw;
}

int			sizecheck(int **oldarr, char *line, int k, t_mlx *mlx)
{
	while (k < mlx->cords.max_y)
	{
		mlx->intarr[k] = oldarr[k];
		k++;
	}
	k = ft_word_count(line, ' ');
	if (k != mlx->wc)
	{
		ft_putstr("Error: x axis not constant\n");
		return (0);
	}
	k = 0;
	mlx->chararr = ft_strsplit(line, ' ');
	mlx->introw = (int *)malloc(sizeof(int) * mlx->cords.max_x);
	while (k < mlx->cords.max_x)
	{
		mlx->introw[k] = ft_atoi(mlx->chararr[k]);
		if (mlx->introw[k] < mlx->cords.min_z)
			mlx->cords.min_z = mlx->introw[k];
		if (mlx->introw[k] > mlx->cords.max_z)
			mlx->cords.max_z = mlx->introw[k];
		k++;
	}
	return (1);
}

int			**fdfreader(int fd, t_mlx *mlx)
{
	int		k;
	char	*line;
	int		**oldarr;

	get_next_line(fd, &line);
	initialread(line, mlx);
	while ((get_next_line(fd, &line)) == 1)
	{
		k = 0;
		oldarr = mlx->intarr;
		mlx->intarr = (int **)malloc(sizeof(int *) * (mlx->cords.max_y + 1));
		if (sizecheck(oldarr, line, k, mlx) == 0)
			return (0);
		mlx->intarr[mlx->cords.max_y] = mlx->introw;
		mlx->cords.max_y++;
		free(line);
		k = 0;
		while (mlx->chararr[k])
			free(mlx->chararr[k++]);
		free(mlx->chararr);
		free(oldarr);
	}
	return (mlx->intarr);
}
