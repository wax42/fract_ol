/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:57:27 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/21 00:10:02 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	fract_fibonacci_normal1(t_p *p, t_fract *l)
{
	if (l->val == 1)
	{
		l->y -= l->size;
		ft_carre(p, *l);
		l->x += l->size;
	}
	else if (l->val == 2)
	{
		l->x -= l->size;
		l->y -= l->size;
		ft_carre(p, *l);
	}
	else if (l->val == 3)
	{
		l->x -= l->size;
		ft_carre(p, *l);
		l->y += l->size;
	}
	l->val++;
}

void	fract_fibonacci_normal(t_p *p, t_fract l)
{
	while (l.i++ < p->iteration_max)
	{
		l.size = ft_fibonacci(l.i);
		if (l.r > 255)
			l.r = p->fract.r;
		if (l.g > 255)
			l.g = p->fract.g;
		if (l.b > 255)
			l.b = p->fract.b;
		l.r += 20;
		l.g += 20;
		l.b += 20;
		if (l.val == 0 || l.val == 4)
		{
			ft_carre(p, l);
			l.x += l.size;
			l.y += l.size;
			l.val = 0;
		}
		fract_fibonacci_normal1(p, &l);
	}
}
