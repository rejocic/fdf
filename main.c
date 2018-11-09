/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 19:23:54 by rejocic           #+#    #+#             */
/*   Updated: 2018/10/10 17:26:56 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		window(t_mlx *mlx)
{
	int		i;

	i = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->cords.max_x * (mlx->\
	sizemult * XMOD), mlx->cords.max_y * (mlx->sizemult * YMOD), "The Void");
	ft_image(mlx);
	mlx_hook(mlx->win_ptr, 17, 0, shut, mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_loop_hook(mlx->mlx_ptr, ft_image, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

void	perspective(t_mlx *mlx)
{
	int		x;
	int		y;
	float	tmp_x;
	float	tmp_y;
	float	tmp_z;

	x = 0;
	y = 0;
	while (y < mlx->cords.max_y)
	{
		while (x < mlx->cords.max_x)
		{
			tmp_z = mlx->cords.height * (mlx->intarr[y][x] - mlx->cords.min_z) \
			/ mlx->cords.max_z;
			tmp_x = x - (mlx->cords.max_x / 2);
			tmp_y = y - (mlx->cords.max_y / 2);
			mlx->floatarr[y][x].u = (tmp_x - tmp_y) * cos(3.14159 / \
			mlx->rotx) + (mlx->cords.max_x / 2) + (mlx->cords.max_x / 2);
			mlx->floatarr[y][x].v = tmp_z * -1 + (tmp_x + tmp_y) * sin(3.14159 \
			/ mlx->roty) + (mlx->cords.max_y / 2) + (2 * mlx->cords.max_y / 3);
			x++;
		}
		y++;
		x = 0;
	}
}

int		sos(int fd, t_mlx *mlx)
{
	int		i;

	i = 0;
	if ((fdfreader(fd, mlx) == 0))
		return (0);
	mlx->maxsize = 1300;
	mlx->sizemult = 30;
	mlx->cords.min_z = 0;
	mlx->cords.height = 3;
	mlx->color = 0;
	mlx->roty = 6;
	mlx->rotx = 6;
	while (mlx->cords.max_x * (mlx->sizemult * XMOD) >= mlx->maxsize || \
	mlx->cords.max_y * (mlx->sizemult * YMOD) >= mlx->maxsize)
		mlx->sizemult--;
	mlx->floatarr = \
	(t_floats **)malloc(sizeof(t_floats *) * mlx->cords.max_y);
	while (i < mlx->cords.max_y)
		mlx->floatarr[i++] = \
		(t_floats *)malloc(sizeof(t_floats) * mlx->cords.max_x);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_mlx	*mlx;

	if (argc >= 2)
	{
		mlx = (t_mlx *)malloc(sizeof(t_mlx));
		if ((fd = open(argv[1], O_RDONLY)) < 0)
		{
			ft_putstr("Error: input must be a file\n");
			return (0);
		}
		if (sos(fd, mlx) == 0)
			return (0);
		window(mlx);
		close(fd);
		free(mlx);
		return (0);
	}
	ft_putchar('\n');
	return (0);
}
