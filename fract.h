/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:11:14 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/14 04:33:20 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACT_H
# define __FRACT_H
# define WIN_X 1200
# define WIN_Y 1400

# include "libft/libft.h"
# include "mlx.h"
# include "math.h"


typedef struct		s_fract
{
	int r;
	int g;
	int b;

	int size;
	int val;
	double x;
	double y;
	double x1;
	double y1;
	double x2;
	double y2;
	int zoom;
	int iteration_max;
	double image_x;
	double image_y;
	double z_r;
	double z_i;
	double c_r;
	double c_i;
	int i;
	double tmp;
}					p_fract;


typedef struct		s_p
{
	void			*mlx;
	void			*win;

	int 			var;
	int				fract;
	int 			iteration_max;
	double 			zoom;
	double 			xmin;
	double 			ymin;
	double			cr;
	double			ci;
	int				mouse_x;
	int				mouse_y;
	int 			var_mouse;

	void			*img;
	char			*map;
	int				bpp;
	int				size_line;
	int				endian;
}					t_p;

int		rgb_to_hexa(int r, int g, int b);

void	mlx_pixel_put_to_image(t_p p, int x, int y, int color);

void 	fract_mandelbrot(t_p *p);

void fract_fibonacci(t_p *p);

int			ft_exit(int i);

void fract_mandelbrot_conjugate(t_p *p);

int		mouse_hook(int x, int y, t_p *p);

int		roll_hook(int button, int x, int y, t_p *p);

void fract_julia(t_p *p);

#endif
