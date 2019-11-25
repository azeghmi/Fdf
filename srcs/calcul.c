/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:07:35 by azeghmi           #+#    #+#             */
/*   Updated: 2019/08/13 14:07:40 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void			rot(t_data *data)
{
	int				i;
	int				j;

	j = 0;
	while (j < data->hlen)
	{
		i = 0;
		while (i < data->wlen)
		{
			data->points[j][i] = rotx(data->points[j][i], data->rotx);
			data->points[j][i] = roty(data->points[j][i], data->roty);
			data->points[j][i] = rotz(data->points[j][i], data->rotz);
			i++;
		}
		j++;
	}
}

static void			shift(t_data *data)
{
	int				i;
	int				j;

	j = 0;
	while (j < data->hlen)
	{
		i = 0;
		while (i < data->wlen)
		{
			data->points[j][i].y = data->points[j][i].y + data->rshift;
			data->points[j][i].z = data->points[j][i].z + data->dshift;
			i++;
		}
		j++;
	}
}

void				calcul(t_data *data)
{
	int				i;
	int				j;

	j = 0;
	while (j < data->hlen)
	{
		i = 0;
		while (i < data->wlen)
		{
			data->points[j][i].x = (j - (data->hlen - 1) / 2.0);
			data->points[j][i].x = data->points[j][i].x * data->space;
			data->points[j][i].y = (i - (data->wlen - 1) / 2.0);
			data->points[j][i].y = data->points[j][i].y * data->space;
			data->points[j][i].z = (-data->data[j][i]);
			i++;
		}
		j++;
	}
	rot(data);
	shift(data);
}
