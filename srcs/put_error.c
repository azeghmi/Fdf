/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:09:36 by azeghmi           #+#    #+#             */
/*   Updated: 2019/08/13 15:48:38 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			put_error(char *desc)
{
	ft_putstr_fd(desc, 2);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
