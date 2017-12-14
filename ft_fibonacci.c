/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:28:17 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/13 15:51:08 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	else if (index < 2)
	{
		return (index);
	}
	else
	{
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	}
}

void 	ft_cercle(t_p *p, p_fract l)
{
	int r;
	int a;
	int x;
	int y;

	y  = l.y;
	x = l.x;

	a = 0;
	r = l.size;
	while (a++ < 360)
	{
		x = cos(a)*r  + l.x;
		y = sin(a)*r + l.y;
		mlx_pixel_put_to_image(*p, x, y, rgb_to_hexa(200, 200, 200));
	}
}

void 	ft_carre(t_p *p, p_fract l)
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


void ft_recur_fibonacci(t_p *p, p_fract l)
{
	while (l.i++ < l.iteration_max)
	{
		l.size = ft_fibonacci(l.i);
		//l.size -= 100;
		ft_putnbr(l.i);
		ft_putchar('\n');
		if (l.r > 255)
			l.r = 55;
		if (l.g > 255)
			l.g = 55;
		if (l.b > 255)
			l.b = 55;
		l.r += 20;
		l.g += 20;
		l.b += 20;
		if (l.val == 0 || l.val == 4)
		{
			ft_carre(p, l);
			ft_cercle(p, l);
			l.x += l.size;
			l.y += l.size;
			l.val = 0;
		}
		else if (l.val == 1)
		{
			l.y -= l.size;
			ft_carre(p, l);
			ft_cercle(p, l);
			l.x += l.size;
		}
		else if (l.val == 2)
		{
			l.x -= l.size;
			l.y -= l.size;
			ft_carre(p, l);
			ft_cercle(p, l);
		}
		else if (l.val == 3)
		{
		  	l.x -= l.size;
			ft_carre(p, l);
			ft_cercle(p, l);
			l.y += l.size;
		}
		l.val++;
	}

}


void fract_fibonacci(t_p *p)
{
	p_fract l;

	l.iteration_max = 20;
	l.x = WIN_X / 2;
	l.y = WIN_Y / 2;
	l.i = -1;
	l.val = 0;
	l.r = 200;
	l.g = 100;
	l.b = 150;
	ft_recur_fibonacci(p, l);
}
