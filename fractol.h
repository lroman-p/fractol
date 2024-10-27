/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroman-p <lroman-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:14:54 by lroman-p          #+#    #+#             */
/*   Updated: 2024/09/30 13:03:31 by lroman-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdbool.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define KEY_ESC 65307
# define KEY_UP 65364
# define KEY_DOWN 65362 
# define KEY_LEFT 65363 
# define KEY_RIGHT 65361
# define KEY_PLUS 43
# define KEY_MINUS 45
# define KEY_SPACE 32
# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct s_complex
{
	double	real;
	double	i;
}				t_complex;

typedef struct s_data
{
	void	*img_ptr;
	char	*address;
	int		bbp;
	int		line_len;
	int		endian;
}				t_data;

typedef struct s_fractol
{
	char	*name;
	void	*ptr_mlx;
	void	*open_w;
	t_data	image;
	int		iterations;
	double	move_x;
	double	move_y;
	double	zoom;
	double	julia_real;
	double	julia_i;
	int		colour;
}				t_fractol;

# define WIDTH 1000
# define HEIGHT 1000

# define NEON_PINK 0XFF1493
//cambio de fondo de colores//
# define GREEN 0xf5ff8a
# define BLUE 0x000d6b
# define PURPLE 0x9c19e0
# define BLUE_2 0x809bce

# define GREEN_MINT 0x99ddcc
//fondo ventana fractal
# define YELLOW 0xfdffb6

# define MSG_ERROR "\n\033[1;31mError:\033[0m Se espera:\n\
	\t\"./fractol mandelbrot\" ó\n\
	\t\"./fractol multibrot\" ó\n\
	\t\"./fractol julia <1>\" ò\n\
	\t\"./fractol julia <2>\" ó\n\
	\t\"./fractol julia <3>\" ó\n\
	\t\"./fractol jullia <4>\"\n\n"	
// rendering_fractol.c//
void		rendering_fractol(t_fractol *fractol);
//events//
void		initialize_event_hooks(t_fractol *fractol);
//main//
void		julia_params(t_fractol *fractol, char **param);
int			main(int argc, char **argv);
// utils hook//
void		zoom_out(t_fractol *fractol, double mouse_x, double mouse_y);
void		zoom_in(t_fractol *fractol, double mouse_x, double mouse_y);
//utils_mat//
double		scale(double value, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_z(t_complex z);
t_complex	cube_z(t_complex z);
//utils//
void		iferror(bool iferror, char *str);
int			ft_strncmp(const char *str1, char *str2, int size);
int			ft_atoi(char *str);
void		perror_exit(void);
//fractol.c//
void		init_fractol(t_fractol *fractol);
#endif
