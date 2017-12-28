/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:13:26 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/21 00:25:59 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	init_struct2(t_p *p)
{
	if (p->withfract == 2)
	{
		p->fract.x1 = -2;
		p->fract.x2 = 1;
		p->fract.y1 = -2;
		p->fract.y2 = 1.2;
		p->fract.zoom = 200;
		p->fract.c_r = 0.285;
		p->fract.c_i = 0.01;
		p->var = -2;
		fract_mandelbrot_conjugate(p);
	}
	if (p->withfract == 3)
	{
		p->fract.x1 = -2;
		p->fract.x2 = 1;
		p->fract.y1 = -2;
		p->fract.y2 = 1.2;
		p->fract.zoom = 200;
		p->fract.c_r = 0.285;
		p->fract.c_i = 0.01;
		fract_mandelbrot(p);
	}
}

static void	init_struct1(t_p *p)
{
	if (p->withfract == 4)
	{
		p->iteration_max = 14;
		p->fract.x = WIN_X / 2;
		p->fract.y = WIN_Y / 2;
		p->fract.i = 0;
		p->fract.val = 0;
		p->fract.r = 150;
		p->fract.g = 20;
		p->fract.b = 100;
		p->fract.fib = 0;
		fract_fibonacci(p);
	}
	if (p->withfract == 5)
	{
		p->iteration_max = 17;
		p->fract.x = WIN_X / 2;
		p->fract.y = WIN_Y / 2;
		p->fract.i = -1;
		p->fract.val = 0;
		p->fract.r = 150;
		p->fract.g = 20;
		p->fract.b = 100;
		fract_fibonacci_normal(p, p->fract);
	}
}

void		init_struct(t_p *p)
{
	p->iteration_max = 40;
	if (p->withfract == 1)
	{
		p->fract.x1 = -2;
		p->fract.x2 = 1;
		p->fract.y1 = -2;
		p->fract.y2 = 1.2;
		p->fract.zoom = 200;
		p->fract.c_r = 0.285;
		p->fract.c_i = 0.01;
		p->var_mouse = 1;
		p->mouse_x = 0;
		p->mouse_y = 0;
		fract_julia(p);
	}
	init_struct1(p);
	init_struct2(p);
}
