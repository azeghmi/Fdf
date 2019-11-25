/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:08:46 by azeghmi           #+#    #+#             */
/*   Updated: 2019/08/13 14:08:48 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point		rotx(t_point point, double t)
{
	t_point	result;

	result.x = point.x;
	result.y = cos(t * PI) * point.y - sin(t * PI) * point.z;
	result.z = sin(t * PI) * point.y + cos(t * PI) * point.z;
	return (result);
}

t_point		roty(t_point point, double t)
{
	t_point	result;

	result.x = cos(t * PI) * point.x + sin(t * PI) * point.z;
	result.y = point.y;
	result.z = -sin(t * PI) * point.x + cos(t * PI) * point.z;
	return (result);
}

t_point		rotz(t_point point, double t)
{
	t_point	result;

	result.x = cos(t * PI) * point.x - sin(t * PI) * point.y;
	result.y = sin(t * PI) * point.x + cos(t * PI) * point.y;
	result.z = point.z;
	return (result);
}
