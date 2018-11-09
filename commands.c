/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:00:44 by rejocic           #+#    #+#             */
/*   Updated: 2018/11/05 13:00:46 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		shut(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
	return (0);
}

int		color_press(int keycode, t_mlx *mlx)
{
	if (keycode == 24)
		mlx->cords.height++;
	if (keycode == 27)
		mlx->cords.height--;
	if (keycode == 18)
		mlx->color = 0;
	if (keycode == 19)
		mlx->color = 1;
	if (keycode == 20)
		mlx->color = 2;
	if (keycode == 21)
		mlx->color = 3;
	if (keycode == 23)
		mlx->color = 4;
	return (0);
}

int		key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53 || keycode == 51)
		exit(0);
	if (keycode >= 18 && keycode <= 27)
		color_press(keycode, mlx);
	if (keycode == 126)
		mlx->roty++;
	if (keycode == 125)
	{
		if (mlx->roty > 2)
			mlx->roty--;
		else
			return (0);
	}
	if (keycode == 123)
		mlx->rotx++;
	if (keycode == 124)
	{
		if (mlx->rotx > 3)
			mlx->rotx--;
		else
			return (0);
	}
	return (0);
}
