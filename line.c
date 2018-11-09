/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 09:44:41 by rejocic           #+#    #+#             */
/*   Updated: 2018/11/05 09:44:42 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_pixel(t_mlx *mlx, int x, int y)
{
	int		j;

	j = 0;
	if (x >= (mlx->cords.max_x * (mlx->sizemult * XMOD)) || \
	y >= (mlx->cords.max_y * (mlx->sizemult * YMOD)) || y < 0)
		return ;
	while (j < (mlx->bpp / 8))
	{
		*(mlx->addr + (mlx->lsize * y + ((mlx->bpp * x) / 8) + j)) = \
		mlx->colorval >> (8 * j) & 0xff;
		j++;
	}
}

void		ft_ifbigdx(int x0, int y0, t_mlx *mlx)
{
	int		d;
	int		d1;
	int		d2;
	int		x;
	int		i;

	d = (mlx->cords.dy * 2) - mlx->cords.dx;
	d1 = mlx->cords.dy * 2;
	d2 = (mlx->cords.dy - mlx->cords.dx) * 2;
	x = x0 + mlx->cords.sx;
	i = 1;
	ft_put_pixel(mlx, x0, y0);
	while (i <= mlx->cords.dx)
	{
		if (d > 0)
		{
			d += d2;
			y0 += mlx->cords.sy;
		}
		else
			d += d1;
		ft_put_pixel(mlx, x, y0);
		i++;
		x += mlx->cords.sx;
	}
}

void		ft_ifsmalldx(int x0, int y0, t_mlx *mlx)
{
	int		d;
	int		d1;
	int		d2;
	int		y;
	int		i;

	d = (mlx->cords.dx * 2) - mlx->cords.dy;
	d1 = mlx->cords.dx * 2;
	d2 = (mlx->cords.dx - mlx->cords.dy) * 2;
	y = y0 + mlx->cords.sy;
	i = 1;
	ft_put_pixel(mlx, x0, y0);
	while (i <= mlx->cords.dy)
	{
		if (d > 0)
		{
			d += d2;
			x0 += mlx->cords.sx;
		}
		else
			d += d1;
		ft_put_pixel(mlx, x0, y);
		i++;
		y += mlx->cords.sy;
	}
}

void		segment(t_floats p0, t_floats p1, t_mlx *mlx)
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;

	x0 = p0.u * mlx->sizemult;
	y0 = p0.v * mlx->sizemult;
	x1 = p1.u * mlx->sizemult;
	y1 = p1.v * mlx->sizemult;
	mlx->cords.dx = abs(x1 - x0);
	mlx->cords.dy = abs(y1 - y0);
	if (x1 >= x0)
		mlx->cords.sx = 1;
	else
		mlx->cords.sx = -1;
	if (y1 >= y0)
		mlx->cords.sy = 1;
	else
		mlx->cords.sy = -1;
	if (mlx->cords.dy >= mlx->cords.dx)
		ft_ifsmalldx(x0, y0, mlx);
	else
		ft_ifbigdx(x0, y0, mlx);
}
