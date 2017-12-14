/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 22:43:45 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/14 04:38:24 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static int		my_key_funct(int keycode, t_p *p)
{
	ft_putstr("\nkey event :");
	ft_putnbr(keycode);
	if (keycode == 53)
		ft_exit(-1);
	if (keycode == 69)
		p->iteration_max += 10;
	if (keycode == 78)
		p->iteration_max -= 10;
	if (keycode == 24)
		p->var += 1;
	if (keycode == 27)
		p->var -= 1;
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->map = mlx_get_data_addr(p->img, &p->bpp, \
	&p->size_line, &p->endian);
	if (p->fract == 1)
		fract_julia(p);
	else if (p->fract == 2)
		fract_mandelbrot_conjugate(p);
	mlx_put_image_to_window(p->mlx, p->win, \
		p->img, 0, 0);
	return (0);
}


void 	init_struct(t_p *p)
{
	p->iteration_max = 40;
	if (p->fract == 1) // init pour julia
	{
		p->zoom = 550;
		p->cr = 0.285;
		p->ci = 0.01;
		p->var_mouse = 1;
		p->mouse_x = 0;
		p->mouse_y = 0;
		p->xmin = 1;
		p->ymin = 1;
		fract_julia(p);
	}
	if (p->fract == 2) // init pour mandelbrot fdp
	{
		p->var = -2;
		fract_mandelbrot_conjugate(p);
	}


}

int				main(int argc, char **argv)
{
	t_p		p;

	if (argc == 2)
	{
		p.mlx = mlx_init();
		p.img = mlx_new_image(p.mlx, WIN_X, WIN_Y);
		p.map = mlx_get_data_addr(p.img, &p.bpp, &p.size_line, &p.endian);
		if (!ft_strcmp(argv[1], "Mandelbrot"))
			fract_mandelbrot(&p);
		if (!ft_strcmp(argv[1], "Fibonacci"))
			fract_fibonacci(&p);
		if (!ft_strcmp(argv[1], "Julia"))
			p.fract = 1;
		if (!ft_strcmp(argv[1], "Mandelbrot_Conjugate"))
			p.fract = 2;
		init_struct(&p);
		//if (!ft_strcmp(argv[1], "Julia"))
			//fract_sierpinski(&p);
		p.win = mlx_new_window(p.mlx, WIN_X, WIN_Y, argv[1]);
		ft_putstr("on va afficher l'image");
		mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
		mlx_hook(p.win, 2, (1L << 0), my_key_funct, &p);
		mlx_hook(p.win, 6, (1L << 6), mouse_hook, &p);
		mlx_hook(p.win, 4, (1L << 2), roll_hook, &p);
		mlx_loop(p.mlx);
	}
	else
		ft_putstr("Usage : ./fractol <filename> [ ex :./fractol Mandelbrot ] \n\t {filename valid: Mandelbrot ,Julia ,Moebius Madness, Quaternion, Buddhabrot, and more}\n");
	return (0);
}
