/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:08:08 by azeghmi           #+#    #+#             */
/*   Updated: 2019/08/13 15:47:37 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			nb_line(char *str)
{
	int		args;
	int		i;

	if (!str)
		return (0);
	args = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
			args++;
		while (str[i] != ' ' && str[i])
			i++;
	}
	return (args);
}

void		nb_args(int const fd, t_data *data)
{
	char	*line;
	int		ret;
	int		max;

	data->wlen = 0;
	data->hlen = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((max = nb_line(line)) > data->wlen)
			data->wlen = max;
		free(line);
		data->hlen++;
	}
	if (ret == -1)
		put_error("Error reading file : nb_args\n");
	if (data->wlen < 2 || data->hlen < 2)
		put_error("Error : Map is too small\n");
}

int			*get_line_args(char *str, int nbr)
{
	int		i;
	int		j;
	int		*args;

	if (!(args = (int*)malloc(nbr * sizeof(int))))
		put_error("Malloc Error : get_line_args\n");
	j = 0;
	while (j < nbr)
		args[j++] = 0;
	if (!str)
		return (args);
	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
			args[j++] = ft_atoi(str + i) * HSPACE;
		while (str[i] != ' ' && str[i])
			i++;
	}
	return (args);
}

void		get_map(int const fd, t_data *data)
{
	char	*line;
	int		ret;
	int		i;

	i = 0;
	if (!(data->data = (int **)malloc(data->hlen * sizeof(int *))))
		put_error("Mem. Alloc. Error : data->data from get_args\n");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		data->data[i] = get_line_args(line, data->wlen);
		free(line);
		i++;
	}
	if (ret == -1)
		put_error("Error reading file : get_args\n");
}
