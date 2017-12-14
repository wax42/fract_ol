/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:27:03 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/14 04:13:13 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"


void fract_mandelbrot(t_p *p)
{
	p_fract l;

	l.x1 = -1.9;
	l.x2 = 0.6;
	l.y1 = -1.2;
	l.y2 = 1.2;
	l.zoom = 500; // pour une distance de 1 sur le plan, on a 100 pixels sur l'image
	l.iteration_max = 100;
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
            	l.z_r =l. z_r * l.z_r - l.z_i * l.z_i + l.c_r;
            	l.z_i = 2 * l.z_i * l.tmp + l.c_i;
            	l.i = l.i + 1;
			}
			(l.i == l.iteration_max) ? mlx_pixel_put_to_image(*p, l.x, l.y, rgb_to_hexa(0, 20, 0)) :\
			mlx_pixel_put_to_image(*p, l.x, l.y, rgb_to_hexa(l.i * 255 / l.iteration_max, 20, 20));
		}
	}
}
