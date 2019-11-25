/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:07:47 by azeghmi           #+#    #+#             */
/*   Updated: 2019/08/13 15:38:26 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static inline void	on_rotate_key(int keycode, t_data *data)
{
	data->autorotate = ~(data->autorotate);
	if (keycode == 13)
		data->roty = data->roty + ROTSTEP;
	else if (keycode == 1)
		data->roty = data->roty - ROTSTEP;
	else if (keycode == 0)
		data->rotx = data->rotx - ROTSTEP;
	else if (keycode == 2)
		data->rotx = data->rotx + ROTSTEP;
	else if (keycode == 12)
		data->rotz = data->rotz - ROTSTEP;
	else if (keycode == 14)
		data->rotz = data->rotz + ROTSTEP;
}

static inline void	on_shift_key(int keycode, t_data *data)
{
	if (keycode == 126)
		data->dshift = data->dshift + SHIFTSTEP;
	else if (keycode == 125)
		data->dshift = data->dshift - SHIFTSTEP;
	else if (keycode == 124)
		data->rshift = data->rshift - SHIFTSTEP;
	else if (keycode == 123)
		data->rshift = data->rshift + SHIFTSTEP;
}

int					key_hook(int keycode, void *param)
{
	t_data			*data;

	data = (t_data *)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode >= 0 && keycode < 15)
		on_rotate_key(keycode, data);
	else if (keycode >= 123 && keycode <= 126)
		on_shift_key(keycode, data);
	else if (keycode == 18)
		data->space = data->space + ZOOMSTEP;
	else if (keycode == 20 && data->space - ZOOMSTEP >= 1)
		data->space = data->space - ZOOMSTEP;
	else if (keycode == 15)
		init(data);
	data->last_press = data->press;
	data->press = keycode;
	calcul(data);
	mlx_clear_window(data->mlx, data->win);
	print(data);
	return (1);
}
