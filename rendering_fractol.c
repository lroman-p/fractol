/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_fractol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroman-p <lroman-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:41:56 by lroman-p          #+#    #+#             */
/*   Updated: 2024/09/28 13:33:12 by lroman-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_data *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->address + (y * img->line_len + x * (img->bbp / 8));
	*(unsigned int *)dst = colour;
}

static void	mand_mult_or_jul(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!(ft_strncmp(fractol->name, "julia", 5)))
	{
		c->real = fractol->julia_real;
		c->i = fractol->julia_i;
	}
	else
	{
		c->real = z->real;
		c->i = z->i;
	}
}

static void	coordenates(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			custom;

	z.real = (scale(x, -2, 2, WIDTH) * fractol->zoom) + fractol->move_x;
	z.i = (scale(y, 2, -2, HEIGHT) * fractol->zoom) + fractol->move_y;
	i = 0;
	mand_mult_or_jul(&z, &c, fractol);
	while (i < fractol->iterations)
	{
		if (!(ft_strncmp(fractol->name, "multibrot", 9)))
			z = sum_complex(cube_z(z), c);
		else
			z = sum_complex(square_z(z), c);
		if (hypot(z.real, z.i) > 2)
		{
			custom = scale(i, YELLOW, NEON_PINK, fractol-> iterations);
			my_mlx_pixel_put(&fractol->image, x, y, custom);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractol->image, x, y, fractol->colour);
}

void	rendering_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			coordenates(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->ptr_mlx,
		fractol->open_w, fractol->image.img_ptr, 0, 0);
}
