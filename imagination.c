/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:10:56 by rejocic           #+#    #+#             */
/*   Updated: 2018/09/15 12:10:58 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		seg_call(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < mlx->cords.max_y)
	{
		while (x < mlx->cords.max_x)
		{
			if (x + 1 < mlx->cords.max_x)
				segment(mlx->floatarr[y][x], mlx->floatarr[y][x + 1], mlx);
			if (y + 1 < mlx->cords.max_y)
				segment(mlx->floatarr[y][x], mlx->floatarr[y + 1][x], mlx);
			x++;
		}
		y++;
		x = 0;
	}
	return ;
}

int			ft_image(t_mlx *mlx)
{
	int		i;

	i = 0;
	mlx->colors = (int *)malloc(sizeof(int) * 5);
	mlx->colors[0] = 0x04dbc9;
	mlx->colors[1] = 0x087a0b;
	mlx->colors[2] = 0xad0808;
	mlx->colors[3] = 0xe0e804;
	mlx->colors[4] = 0xf9fafc;
	if (mlx->cords.max_z == 0)
		mlx->cords.max_z = 1;
	perspective(mlx);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->cords.max_x * \
	(mlx->sizemult * XMOD), mlx->cords.max_y * (mlx->sizemult * YMOD));
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp), \
	&(mlx->lsize), &(mlx->endian));
	mlx->colorval = mlx_get_color_value(mlx->mlx_ptr, mlx->colors[mlx->color]);
	seg_call(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 8, 3, 0xf9fafc, "1-5 color");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 8, 23, 0xf9fafc, "^ & v rotate");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 8, 43, 0xf9fafc, "+ & - height");
	free(mlx->colors);
	return (0);
}
