/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:05:33 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/14 03:38:07 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void fract_julia(t_p *p)
{
	p_fract l;

	l.x1 = -1;
	l.x2 = 1;
	l.y1 = -1.1;
	l.y2 = 1.2;
	l.zoom = p->zoom; // pour une distance de 1 sur le plan, on a 100 pixels sur l'image
	l.iteration_max = p->iteration_max;
	l.c_r = p->cr;
	l.c_i = p->ci;
//	l.x1 = p->mouse_x - p->xmin;
//	l.x2 = p->mouse_x + p->xmin;

//	l.y1 = p->mouse_y - p->ymin;
// 	l.y2 = p->mouse_y + p->ymin;

//De même si vous voulez zoomer sur un point du plan complexe de coordonné (x; y) en particulier,
//il faudra juste définir x1 = x-h, x2 = x+h, y1 = y-h et y2 = y+h.
//Avec h un valeur que vous fixerez vous-même en sachant que plus elle est petite, plus vous zoomerez sur ce point en particulier.
//Bien évidement, il faudra augmenter en conséquence le zoom et le nombre d'itérations.
	l.image_x = (l.x2 - l.x1) * l.zoom;
	l.image_y = (l.y2 - l.y1) * l.zoom;

	l.x = 0;
	while (l.x++ < l.image_x)
	{
		l.y = 0;
		while (l.y++ < l.image_y)
		{
        	l.z_r =  l.x / l.zoom + l.x1;
        	l.z_i =  l.y / l.zoom + l.y1;
        	l.i = 0;
			while ((l.z_r * l.z_r + l.z_i * l.z_i < 4) && (l.i < l.iteration_max))
            {
				l.tmp = l.z_r;
            	l.z_r =l. z_r * l.z_r - l.z_i * l.z_i + l.c_r;
            	l.z_i = 2 * l.z_i * l.tmp + l.c_i;
            	l.i = l.i + 1;
			}
			(l.i == l.iteration_max) ? mlx_pixel_put_to_image(*p, l.x, l.y, rgb_to_hexa(200, 50, 100)) :\
			mlx_pixel_put_to_image(*p, l.x, l.y, rgb_to_hexa(0, 0, l.i * 255 / l.iteration_max));
		}
	}
}
