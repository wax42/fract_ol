/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:07:24 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/20 23:43:20 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_carre(t_p *p, t_fract l)
{
	int x;
	int y;

	y = l.y;
	while (y < l.size + l.y)
	{
		x = l.x;
		while (x < l.size + l.x)
		{
			mlx_pixel_put_to_image(*p, x, y, rgb_to_hexa(l.r, l.g, l.b));
			x++;
		}
		y++;
	}
}
