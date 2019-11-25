/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:08:25 by azeghmi           #+#    #+#             */
/*   Updated: 2019/08/13 14:08:27 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_lign_vert(void *mlx, void *win, t_point a, t_point b)
{
	int		i;

	i = (int)a.z;
	while (i < (int)b.z)
	{
		mlx_pixel_put(mlx, win, (int)a.y, i, 0xFFFFFF);
		i++;
	}
}

void	print_lign_zp(void *mlx, void *win, t_point a, t_point b)
{
	double	slope;
	double	ord;
	int		i;

	slope = (b.z - a.z) / (b.y - a.y);
	ord = a.z - slope * a.y;
	i = (int)a.z;
	while (i <= (int)b.z)
	{
		mlx_pixel_put(mlx, win, (int)((i - ord) / slope), i, 0xFFFFFF);
		i++;
	}
}

void	print_lign_zm(void *mlx, void *win, t_point a, t_point b)
{
	double	slope;
	double	ord;
	int		i;

	slope = (b.z - a.z) / (b.y - a.y);
	ord = a.z - slope * a.y;
	i = (int)a.z;
	while (i >= (int)b.z)
	{
		mlx_pixel_put(mlx, win, (int)((i - ord) / slope), i, 0xFFFFFF);
		i--;
	}
}

void	print_lign_y(void *mlx, void *win, t_point a, t_point b)
{
	double	slope;
	double	ord;
	int		i;

	slope = (b.z - a.z) / (b.y - a.y);
	ord = a.z - slope * a.y;
	i = (int)a.y;
	while (i <= (int)b.y)
	{
		mlx_pixel_put(mlx, win, i, (int)(i * slope + ord), 0xFFFFFF);
		i++;
	}
}

void	print_lign(void *mlx, void *win, t_point a, t_point b)
{
	if ((int)a.y == (int)b.y && a.z - b.z < 0)
		print_lign_vert(mlx, win, a, b);
	else if ((int)a.y == (int)b.y)
		print_lign_vert(mlx, win, b, a);
	else if ((int)a.y > (int)b.y)
		print_lign(mlx, win, b, a);
	else if ((int)(b.z - a.z) > 0 && (int)(b.z - a.z) > (int)(b.y - a.y))
		print_lign_zp(mlx, win, a, b);
	else if ((int)(b.z - a.z) < 0 && (int)-(b.z - a.z) > (int)(b.y - a.y))
		print_lign_zm(mlx, win, a, b);
	else
		print_lign_y(mlx, win, a, b);
}
