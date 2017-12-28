/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_conjugate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 04:18:59 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/21 00:34:31 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	fract_mandelbrot_conjugate2(t_p *p)
{
	while (p->fract.y++ < p->fract.image_y)
	{
		p->fract.c_r = p->fract.x / p->fract.zoom + p->fract.x1;
		p->fract.c_i = p->fract.y / p->fract.zoom + p->fract.y1;
		p->fract.z_r = 0;
		p->fract.z_i = 0;
		p->fract.i = 0;
		while ((p->fract.z_r * p->fract.z_r + p->fract.z_i * p->fract.z_i <\
			4) && (++p->fract.i < p->iteration_max))
		{
			p->fract.tmp = p->fract.z_r;
			p->fract.z_r = p->fract.z_r * p->fract.z_r - p->fract.z_i \
			* p->fract.z_i + p->fract.c_r;
			p->fract.z_i = p->var * p->fract.z_i * p->fract.tmp + p->fract.c_i;
		}
		(p->fract.i == p->iteration_max) ? mlx_pixel_put_to_image(*p, \
			p->fract.x, p->fract.y, rgb_to_hexa(0, 20, 0)) :\
		mlx_pixel_put_to_image(*p, p->fract.x, p->fract.y, rgb_to_hexa(20, \
			p->fract.i * 255 / p->iteration_max, 20));
	}
}

void		fract_mandelbrot_conjugate(t_p *p)
{
	p->fract.image_x = (p->fract.x2 - p->fract.x1) * p->fract.zoom + 300;
	p->fract.image_y = (p->fract.y2 - p->fract.y1) * p->fract.zoom + 300;
	p->fract.x = 0;
	while (p->fract.x++ < p->fract.image_x)
	{
		p->fract.y = 0;
		fract_mandelbrot_conjugate2(p);
	}
}
