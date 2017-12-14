/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_to_img.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:01:16 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/11 23:37:48 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	mlx_pixel_put_to_image(t_p p, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = WIN_X * WIN_Y * p.bpp / 8;
	if (x < 0 || y < 0 || y * p.size_line + x * p.bpp / 8 > \
		img_size
		|| x >= p.size_line / (p.bpp / 8) || y >= img_size / \
		p.size_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = p.bpp / 8;
	p.map[y * p.size_line + x * bit_pix] = color1;
	p.map[y * p.size_line + x * bit_pix + 1] = color2;
	p.map[y * p.size_line + x * bit_pix + 2] = color3;
}
