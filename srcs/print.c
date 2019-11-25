/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:08:33 by azeghmi           #+#    #+#             */
/*   Updated: 2019/08/13 14:08:35 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->hlen)
	{
		i = 0;
		while (i < data->wlen)
		{
			if (i + 1 < data->wlen)
				print_lign(data->mlx, data->win, data->points[j][i],
					data->points[j][i + 1]);
			if (j + 1 < data->hlen)
			{
				print_lign(data->mlx, data->win, data->points[j][i],
					data->points[j + 1][i]);
			}
			i++;
		}
		j++;
	}
}
