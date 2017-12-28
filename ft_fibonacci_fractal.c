/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:28:17 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/21 14:48:41 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_draw_carre_fibonnaci_2(t_p *p, t_fract *l)
{
	if (l->val == 3)
	{
		l->x -= l->size;
		ft_carre(p, *l);
		l->y += l->size;
		l->g += 20;
	}
}

void	ft_draw_carre_fibonnaci_1(t_p *p, t_fract *l)
{
	if (l->val == 0 || l->val == 4)
	{
		ft_carre(p, *l);
		l->x += l->size;
		l->y += l->size;
		l->val = 0;
		l->r += 20;
	}
	else if (l->val == 1)
	{
		l->y -= l->size;
		ft_carre(p, *l);
		l->x += l->size;
		l->g += 20;
	}
	else if (l->val == 2)
	{
		l->x -= l->size;
		l->y -= l->size;
		ft_carre(p, *l);
	}
	ft_draw_carre_fibonnaci_2(p, l);
}

void	ft_draw_carre_fibonnaci(t_p *p, t_fract r)
{
	t_fract l;

	l.i = 0;
	l.x = r.x;
	l.y = r.y;
	l.r = p->fract.r;
	l.g = p->fract.g;
	l.b = p->fract.b;
	l.iteration_max = r.i - 1;
	while (l.i++ < l.iteration_max)
	{
		l.size = ft_fibonacci(l.i);
		(l.r > 255) ? (l.r = p->fract.r) : (l.r);
		(l.g > 255) ? (l.g = p->fract.g) : (l.g);
		(l.b > 255) ? (l.b = p->fract.b) : (l.b);
		ft_draw_carre_fibonnaci_1(p, &l);
		ft_draw_carre_fibonnaci(p, l);
		l.val++;
	}
}

void	fract_fibonacci(t_p *p)
{
	if (p->iteration_max > 18)
		p->iteration_max = 19;
	p->fract.iteration_max = p->iteration_max;
	ft_recur_fibonacci(p, p->fract);
}
