/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroman-p <lroman-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:41:43 by lroman-p          #+#    #+#             */
/*   Updated: 2024/09/28 13:30:08 by lroman-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	init_util_data(t_fractol *fractol)
{
	fractol->iterations = 20;
	fractol->move_x = 0.0;
	fractol->move_y = 0.0;
	fractol->zoom = 1.0;
	fractol->colour = GREEN;
}

void	init_fractol(t_fractol *fractol)
{
	fractol->ptr_mlx = mlx_init();
	iferror(fractol->ptr_mlx == NULL, "mlx_init failed");
	fractol->open_w = mlx_new_window(fractol-> ptr_mlx,
			WIDTH, HEIGHT, fractol->name);
	iferror(fractol->open_w == NULL, "mlx_new_window failed");
	fractol->image.img_ptr = mlx_new_image(fractol->ptr_mlx, WIDTH, HEIGHT);
	if (fractol-> image.img_ptr == NULL)
	{
		if (fractol->open_w != NULL)
			mlx_clear_window (fractol->ptr_mlx, fractol->open_w);
		perror("mlx_nex_image failed");
		exit(EXIT_FAILURE);
	}
	fractol->image.address = mlx_get_data_addr(fractol->image.img_ptr,
			&fractol->image.bbp, &fractol->image.line_len,
			&fractol->image.endian);
	if (fractol->image.address == NULL)
	{
		perror("mlx_get_data_addr failed");
		exit(EXIT_FAILURE);
	}
	init_util_data(fractol);
	initialize_event_hooks(fractol);
}
