/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_conjugate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 04:18:59 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/14 04:37:45 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void fract_mandelbrot_conjugate(t_p *p)
{
	p_fract l;

	l.x1 = -2.1;
	l.x2 = 1.8;
	l.y1 = -1.7;
	l.y2 = 2.3;
	l.zoom = 300; // pour une distance de 1 sur le plan, on a 100 pixels sur l'image
	l.iteration_max = p->iteration_max;
	l.image_x = (l.x2 - l.x1) * l.zoom;
	l.image_y = (l.y2 - l.y1) * l.zoom;

	l.x = 0;
	while (l.x++ < l.image_x)
	{
		l.y = 0;
		while (l.y++ < l.image_y)
		{
			l.c_r = l.x / l.zoom + l.x1;
        	l.c_i = l.y / l.zoom + l.y1;
        	l.z_r = 0;
        	l.z_i = 0;
        	l.i = 0;
			while ((l.z_r * l.z_r + l.z_i * l.z_i < 4) && (l.i < l.iteration_max))
            {
				l.tmp = l.z_r;
            	l.z_r = l.z_r * l.z_r - l.z_i * l.z_i + l.c_r;
            	l.z_i = p->var * l.z_i * l.tmp + l.c_i;
            	l.i = l.i + 1;
			}
			(l.i == l.iteration_max) ? mlx_pixel_put_to_image(*p, l.x, l.y, rgb_to_hexa(0, 20, 0)) :\
			mlx_pixel_put_to_image(*p, l.x, l.y, rgb_to_hexa(20, l.i * 255 / l.iteration_max, 20));
		}
	}
}
