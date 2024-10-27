/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroman-p <lroman-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:25:30 by lroman-p          #+#    #+#             */
/*   Updated: 2024/09/30 10:29:24 by lroman-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double value, double new_mim, double new_max, double old_max)
{
	return ((new_max - new_mim) * (value - 0) / (old_max - 0) + new_mim);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	value;

	value.real = (z1.real + z2.real);
	value.i = (z1.i + z2.i);
	return (value);
}

t_complex	square_z(t_complex z)
{
	t_complex	value;

	value.real = pow(z.real, 2) - pow(z.i, 2);
	value.i = 2 * z.real * z.i;
	return (value);
}

t_complex	cube_z(t_complex z)
{
	t_complex	result;

	result.real = pow(z.real, 3) - 3 * z.real * pow(z.i, 2);
	result.i = 3 * pow(z.real, 2) * z.i - pow (z.i, 3);
	return (result);
}
