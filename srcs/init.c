/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:09:01 by azeghmi           #+#    #+#             */
/*   Updated: 2019/08/13 15:59:17 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init(t_data *data)
{
	int i;

	data->space = (((WIDTH <= HEIGHT) ? WIDTH : HEIGHT) - PADDING * 2) /
		(((data->wlen >= data->hlen) ? data->wlen : data->hlen) - 1);
	if (data->space < 1)
		data->space = 1;
	data->dshift = HEIGHT / 2;
	data->rshift = WIDTH / 2;
	data->rotx = ROTX;
	data->roty = ROTY;
	data->rotz = ROTZ;
	if (!(data->points = (t_point **)malloc(data->hlen * sizeof(t_point *))))
		return ;
	i = 0;
	while (i < data->hlen)
	{
		data->points[i] = (t_point *)malloc(data->wlen * sizeof(t_point));
		if (!(data->points[i]))
			return ;
		i++;
	}
}
