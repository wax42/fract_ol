/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 22:43:45 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/21 15:36:00 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static int		my_key_funct_3(int keycode, t_p *p)
{
	if (keycode == 124)
		p->fract.x1 -= 0.1;
	if (keycode == 123)
		p->fract.x1 += 0.1;
	if (keycode == 125)
		p->fract.y1 -= 0.1;
	if (keycode == 126)
		p->fract.y1 += 0.1;
	return (0);
}

static int		my_key_funct_2(int keycode, t_p *p)
{
	if (keycode == 84)
	{
		p->withfract = 2;
		init_struct(p);
	}
	if (keycode == 85)
	{
		p->withfract = 3;
		init_struct(p);
	}
	if (keycode == 86)
	{
		p->withfract = 4;
		init_struct(p);
	}
	if (keycode == 87)
	{
		p->withfract = 5;
		init_struct(p);
	}
	if (keycode == 34)
		init_struct(p);
	my_key_funct_3(keycode, p);
	ft_which_fractal(p);
	return (0);
}

static int		my_key_funct(int keycode, t_p *p)
{
	if (keycode == 53)
		ft_exit(-1);
	if (keycode == 69)
		p->iteration_max += 1;
	if (keycode == 78 && p->iteration_max > 2)
		p->iteration_max -= 1;
	if (keycode == 24)
		p->var += 1;
	if (keycode == 27)
		p->var -= 1;
	(keycode == 35) ? (p->var_mouse = abs(p->var_mouse - 1)) : (p->var_mouse);
	if (keycode == 83)
	{
		p->withfract = 1;
		init_struct(p);
	}
	my_key_funct_2(keycode, p);
	return (0);
}

static void		multiple_arg(char **argv, int argc, t_p *p)
{
	if (!ft_strcmp(argv[argc], "Mandelbrot"))
		p->withfract = 3;
	else if (!ft_strcmp(argv[argc], "Fibonacci"))
		p->withfract = 4;
	else if (!ft_strcmp(argv[argc], "Fibonacci_normal"))
		p->withfract = 5;
	else if (!ft_strcmp(argv[argc], "Julia"))
		p->withfract = 1;
	else if (!ft_strcmp(argv[argc], "Mandelbrot_Conjugate"))
		p->withfract = 2;
	else
		ft_exit(0);
}

int				main(int argc, char **argv)
{
	t_p		p;

	if (argc == 2)
	{
		multiple_arg(argv, 1, &p);
		p.mlx = mlx_init();
		p.img = mlx_new_image(p.mlx, WIN_X, WIN_Y);
		p.map = mlx_get_data_addr(p.img, &p.bpp, &p.size_line, &p.endian);
		init_struct(&p);
		p.win = mlx_new_window(p.mlx, WIN_X, WIN_Y, argv[1]);
		mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
		mlx_hook(p.win, 2, (1L << 0), my_key_funct, &p);
		mlx_hook(p.win, 6, (1L << 6), mouse_hook, &p);
		mlx_hook(p.win, 4, (1L << 2), roll_hook, &p);
		mlx_loop(p.mlx);
	}
	else
		ft_exit(0);
	return (0);
}
