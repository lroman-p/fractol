/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroman-p <lroman-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:06:12 by lroman-p          #+#    #+#             */
/*   Updated: 2024/09/28 13:34:29 by lroman-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_out(t_fractol	*fractol, double mouse_x, double mouse_y)
{
	fractol->zoom *= 0.9;
	fractol->move_x += mouse_x / (0.5 * WIDTH * fractol->zoom);
	fractol->move_y += mouse_y / (0.5 * HEIGHT * fractol->zoom);
}

void	zoom_in(t_fractol	*fractol, double mouse_x, double mouse_y)
{
	fractol->zoom *= 1.1;
	fractol->move_x -= mouse_x / (0.5 * WIDTH * fractol->zoom);
	fractol->move_y -= mouse_y / (0.5 * HEIGHT * fractol->zoom);
}
