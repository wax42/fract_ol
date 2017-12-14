/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rool_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:37:05 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/14 03:24:06 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include <stdio.h>

static void	roll_hook1(int button, int x, int y, t_p *p)
{
	printf("%s    %d\n"," Key Event :",button);
	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
	{
		if (button == 1 || button == 4)
		{
			p->zoom *= 1.1;
			p->xmin = p->xmin + ((double)x - ((double)WIN_X / 2)) \
			/ p->zoom;
			p->ymin = p->ymin + ((double)y - ((double)WIN_Y / 2)) \
			/ p->zoom;
		}
		if (button == 2 || button == 5)
		{
			p->zoom *= 0.9;
			p->xmin = p->xmin + ((double)x - ((double)WIN_X / 2)) \
			/ p->zoom;
			p->ymin = p->ymin + ((double)y - ((double)WIN_Y / 2)) \
			/ p->zoom;
		}
	}
}

int		roll_hook(int button, int x, int y, t_p *p)
{
	roll_hook1(button, x, y, p);
	p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->map = mlx_get_data_addr(p->img, &p->bpp, \
		&p->size_line, &p->endian);
	fract_julia(p);
	mlx_put_image_to_window(p->mlx, p->win, \
		p->img, 0, 0);
	return (0);
}


static void	mouse_hook1(int x, int y, t_p *p)
{
	if (x < (WIN_X) && y < (WIN_Y))
	{
		p->cr = (x < p->mouse_x) ? (p->cr + 0.01) : \
		(p->cr - 0.01);
		p->ci = (y < p->mouse_y) ? (p->ci + 0.01) : \
		(p->ci - 0.01);
	}
}

int		mouse_hook(int x, int y, t_p *p)
{
	if (x >= 0 && x <= WIN_X && y >= 0 && y <= WIN_Y)
	{
		if (p->var_mouse == 1)
		{
			mouse_hook1(x, y, p);
		}
		p->mouse_x = x;
		p->mouse_y = y;
	}
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->map = mlx_get_data_addr(p->img, &p->bpp, \
		&p->size_line, &p->endian);
	fract_julia(p);
	mlx_put_image_to_window(p->mlx, p->win, \
		p->img, 0, 0);
	return (0);
}
