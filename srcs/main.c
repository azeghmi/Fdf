/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:09:21 by azeghmi           #+#    #+#             */
/*   Updated: 2019/08/13 16:27:05 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#define CLOSEFD(x)	if (close(x) < 0) {return (EXIT_FAILURE);}

static inline int	ft_valid_file_fmt(char const *file)
{
	char			*ptr;

	if ((ptr = ft_strrchr(file, '.')) == NULL)
		return (-1);
	return (ft_strcmp(ptr, ".fdf"));
}

static inline int	ft_reset_fd(int fd, char const *file)
{
	if (close(fd) < 0)
		return (-1);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	return (fd);
}

static int			autorotate(void *data)
{
	t_data			*parameters;

	parameters = (t_data *)data;
	if (parameters->autorotate == 0)
		return (1);
	if (parameters->press == 13)
		parameters->roty = parameters->roty + ROTSTEP;
	else if (parameters->press == 1)
		parameters->roty = parameters->roty - ROTSTEP;
	else if (parameters->press == 0)
		parameters->rotx = parameters->rotx - ROTSTEP;
	else if (parameters->press == 2)
		parameters->rotx = parameters->rotx + ROTSTEP;
	else if (parameters->press == 12)
		parameters->rotz = parameters->rotz - ROTSTEP;
	else if (parameters->press == 14)
		parameters->rotz = parameters->rotz + ROTSTEP;
	else
		return (1);
	calcul(parameters);
	mlx_clear_window(parameters->mlx, parameters->win);
	print(parameters);
	return (1);
}

int					main(int argc, char **argv)
{
	int				fd;
	t_data			data;

	if (argc != 2)
		put_error("usage: ./fdf [map]\n");
	if (ft_valid_file_fmt(argv[1]) != 0)
		put_error("fdf: Not a valid fdf file\n");
	fd = open(argv[1], O_RDONLY);
	ft_bzero(&data, sizeof(data));
	nb_args(fd, &data);
	if (ft_reset_fd(fd, argv[1]) < 0)
		return (EXIT_FAILURE);
	get_map(fd, &data);
	CLOSEFD(fd);
	init(&data);
	calcul(&data);
	if ((data.mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fdf")) == NULL)
		return (EXIT_FAILURE);
	print(&data);
	mlx_loop_hook(data.mlx, &autorotate, &data);
	mlx_key_hook(data.win, &key_hook, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
