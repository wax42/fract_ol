/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 04:43:10 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/21 00:28:53 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_which_fractal(t_p *p)
{
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->map = mlx_get_data_addr(p->img, &p->bpp, \
	&p->size_line, &p->endian);
	if (p->withfract == 1)
		fract_julia(p);
	else if (p->withfract == 2)
		fract_mandelbrot_conjugate(p);
	else if (p->withfract == 3)
		fract_mandelbrot(p);
	else if (p->withfract == 4)
		fract_fibonacci(p);
	else if (p->withfract == 5)
		fract_fibonacci_normal(p, p->fract);
	mlx_put_image_to_window(p->mlx, p->win, \
		p->img, 0, 0);
}
