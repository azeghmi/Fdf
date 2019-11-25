/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 23:54:42 by azeghmi           #+#    #+#             */
/*   Updated: 2019/08/13 15:47:49 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define HEIGHT			812
# define WIDTH			1024
# define PADDING		50
# define HSPACE			8
# define ROTX			0.0
# define ROTY			0.0
# define ROTZ			0.0
# define ROTSTEP		0.005
# define ZOOMSTEP		10
# define SHIFTSTEP		35
# define PI				3.14159265358979323846

typedef struct	s_point {
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_data {
	void		*mlx;
	void		*win;
	int			**data;
	int			wlen;
	int			hlen;
	int			space;
	int			dshift;
	int			rshift;
	int			press;
	int			autorotate;
	int			last_press;
	double		rotx;
	double		roty;
	double		rotz;
	t_point		**points;
}				t_data;

int				nb_line(char *str);
int				key_hook(int keycode, void *param);
int				put_error(char *desc);
void			calcul(t_data *data);
void			init(t_data *data);
void			nb_args(int const fd, t_data *data);
void			get_map(int const fd, t_data *data);
void			print(t_data *data);
void			print_lign(void *mlx, void *win, t_point a, t_point b);
t_point			rotx(t_point point, double t);
t_point			roty(t_point point, double t);
t_point			rotz(t_point point, double t);

#endif
