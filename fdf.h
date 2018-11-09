/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:11:54 by rejocic           #+#    #+#             */
/*   Updated: 2018/09/08 13:59:15 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define XMOD 2
# define YMOD 2

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef	struct		s_floats
{
	float			u;
	float			v;
}					t_floats;

typedef	struct		s_cords
{
	int				height;
	int				z;
	int				max_x;
	int				max_y;
	float			max_z;
	float			min_z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
}					t_cords;

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	int				bpp;
	int				lsize;
	int				native_american;
	char			**chararr;
	int				*introw;
	int				**intarr;
	t_floats		**floatarr;
	unsigned int	colorval;
	int				*colors;
	int				color;
	int				sizemult;
	int				maxsize;
	t_cords			cords;
	int				roty;
	int				rotx;
	int				wc;
}					t_mlx;

int					shut(t_mlx *ptrs);
int					key_press(int keycode, t_mlx *ptrs);
int					**fdfreader(int fd, t_mlx *mlx);
int					window(t_mlx *mlx);
int					ft_image(t_mlx *mlx);
void				perspective(t_mlx *mlx);
void				niceone(t_mlx *mlx);
void				ft_put_pixel(t_mlx *mlx, int x, int y);
void				ft_ifbigdx(int x0, int y0, t_mlx *mlx);
void				ft_ifsmalldx(int x0, int y0, t_mlx *mlx);
void				segment(t_floats p0, t_floats p1, t_mlx *mlx);
int					shut(t_mlx *mlx);
int					color_press(int keycode, t_mlx *mlx);
int					key_press(int keycode, t_mlx *mlx);

#endif
